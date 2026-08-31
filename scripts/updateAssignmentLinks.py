import re

import canvasIntegration
import githubIntegration
from metadataLoader import loadMetadata


def chooseAssignment(assignments: list):
    print("Assignments in the course:")
    for index, assignment in enumerate(assignments, start=1):
        print(f"{index}. {assignment.name} (ID: {assignment.id})")

    while True:
        try:
            assignment_number = int(input("Enter the number of the assignment to update: "))
            if 1 <= assignment_number <= len(assignments):
                return assignments[assignment_number - 1]
            print(f"Please enter a number between 1 and {len(assignments)}.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")


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


if __name__ == "__main__":
    metadata = loadMetadata()
    canvas_client = canvasIntegration.createCanvasClient(metadata)
    course = canvas_client.get_course(metadata["courseID"])
    assignment_list = list(canvasIntegration.getCanvasExercises(course))

    if not assignment_list:
        raise RuntimeError("No assignments found in the course.")

    selected_assignment = chooseAssignment(assignment_list)
    assignment = course.get_assignment(selected_assignment.id)
    current_description = assignment.description or ""

    github_url = githubIntegration.getGithubURL(assignment.name)
    updated_description = replaceAssignmentLink(current_description, github_url)
    print(f"Will update the 'Opdracht link' link in '{assignment.name}' to:")
    print(github_url)
    if input("Apply this update? [y/N]: ").strip().lower() != "y":
        print("No changes were made.")
    else:
        updated_assignment = canvasIntegration.updateAssignmentDescription(
            assignment, {"description": updated_description}
        )
        verified_assignment = course.get_assignment(updated_assignment.id)
        verified_url = getAssignmentLink(verified_assignment.description or "")
        if verified_url != github_url:
            raise RuntimeError(
                "Canvas did not store the expected 'Opdracht link' link. "
                f"Stored link: {verified_url}"
            )
        print(
            f"Successfully verified assignment '{verified_assignment.name}' "
            f"(ID: {verified_assignment.id})."
        )