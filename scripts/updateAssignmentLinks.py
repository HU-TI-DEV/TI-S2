import re

import canvasIntegration
import githubIntegration
from metadataLoader import loadMetadata


ASSIGNMENT_LINK_PATTERN = r"(<p>\s*Opdracht link:\s*<a\b[^>]*\bhref=[\"'])([^\"']*)([\"'])"


def replaceAssignmentLink(description: str, github_url: str) -> str:
    updated_description, replacement_count = re.subn(
        ASSIGNMENT_LINK_PATTERN,
        rf"\g<1>{github_url}\g<3>",
        description,
        count=1,
        flags=re.IGNORECASE,
    )
    if replacement_count == 0:
        raise ValueError("The description does not contain an 'Opdracht link' link.")

    return updated_description


def getAssignmentLink(description: str) -> str:
    match = re.search(ASSIGNMENT_LINK_PATTERN, description, flags=re.IGNORECASE)
    if not match:
        raise ValueError("The description does not contain an 'Opdracht link' link.")
    return match.group(2)


def findAssignmentsToUpdate(course, assignments: list) -> list[tuple]:
    assignments_to_update = []
    for assignment_summary in assignments:
        assignment = course.get_assignment(assignment_summary.id)
        description = assignment.description or ""
        try:
            github_url = githubIntegration.getGithubURL(assignment.name)
            current_url = getAssignmentLink(description)
        except (FileNotFoundError, ValueError):
            continue

        if current_url != github_url:
            assignments_to_update.append(
                (assignment, replaceAssignmentLink(description, github_url), github_url)
            )
    return assignments_to_update


if __name__ == "__main__":
    metadata = loadMetadata()
    canvas_client = canvasIntegration.createCanvasClient(metadata)
    course = canvas_client.get_course(metadata["courseID"])
    assignment_list = list(canvasIntegration.getCanvasExercises(course))

    if not assignment_list:
        raise RuntimeError("No assignments found in the course.")

    assignments_to_update = findAssignmentsToUpdate(course, assignment_list)
    if not assignments_to_update:
        print("No assignment links need updating.")
        raise SystemExit(0)

    print("Assignments with an outdated 'Opdracht link':")
    for assignment, _, github_url in assignments_to_update:
        print(f"- {assignment.name} (ID: {assignment.id}): {github_url}")

    if input("Apply this update? [y/N]: ").strip().lower() != "y":
        print("No changes were made.")
    else:
        for assignment, updated_description, github_url in assignments_to_update:
            updated_assignment = canvasIntegration.updateAssignmentDescription(
                assignment, {"description": updated_description}
            )
            verified_assignment = course.get_assignment(updated_assignment.id)
            verified_url = getAssignmentLink(verified_assignment.description or "")
            if verified_url != github_url:
                raise RuntimeError(
                    "Canvas did not store the expected 'Opdracht link' link for "
                    f"'{assignment.name}'. Stored link: {verified_url}"
                )
            print(f"Successfully verified '{verified_assignment.name}' (ID: {verified_assignment.id}).")