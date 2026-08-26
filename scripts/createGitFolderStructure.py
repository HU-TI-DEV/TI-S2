import canvasIntegration as canvasIntegration
import githubIntegration as githubIntegration
from metadataLoader import loadMetadata

if __name__ == "__main__":
    # Connect to Canvas Course using metadata
    metadata = loadMetadata()
    canvas_client = canvasIntegration.createCanvasClient(metadata)
    course = canvas_client.get_course(metadata["courseID"])

    # Get the list of assignments in the course
    assignments = canvasIntegration.getCanvasExercises(course)
    assignment_list = list(assignments)

    if not assignment_list:
        raise RuntimeError("No assignments found in the course.")

    # Check if the opdrachten folder exists in the root directory and make it if it doesn't
    root_path = githubIntegration.get_root()
    opdrachten_folder = root_path / "opdrachten"
    opdrachten_folder.mkdir(exist_ok=True)

    # Iterate over the assignments and create a folder for each unique assignment.assignment_group_id if it doesn't exist yet. If it does, create an empty .md file with the name of the assignment in said folder. If the assignment already has a corresponding .md file, skip it.
    for assignment in assignment_list:
        assignment_group_folder = opdrachten_folder / str(assignment.assignment_group_id)
        assignment_group_folder.mkdir(exist_ok=True)

        assignment_md_file = assignment_group_folder / f"{assignment.name}.md"
        if not assignment_md_file.exists():
            assignment_md_file.touch()
            print(f"Created new markdown file: {assignment_md_file}")
        else:
            print(f"Markdown file already exists: {assignment_md_file}")
