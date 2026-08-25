import canvasIntegration
import githubIntegration
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

    # Make a numbered list of assignment names for reference
    print("Assignments in the course:")
    for idx, assignment in enumerate(assignment_list, start=1):
        print(f"{idx}. {assignment.name} (ID: {assignment.id})")

    # Ask the user to pick an assignment by number
    while True:
        try:
            assignment_number = int(input("Enter the number of the assignment to update: "))
            if 1 <= assignment_number <= len(assignment_list):
                selected_assignment = assignment_list[assignment_number - 1]
                break
            else:
                print(f"Please enter a number between 1 and {len(assignment_list)}.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")

    # Update the given assignment with the examination info from Github
    opdrachtnaam = selected_assignment.name
    try:
        examination_info = githubIntegration.getExaminationInfo(opdrachtnaam)
        updated_assignment = canvasIntegration.updateAssignmentDescription(selected_assignment, examination_info)
        print(f"Successfully updated assignment '{updated_assignment.name}' (ID: {updated_assignment.id}) with new description.")
    except Exception as e:
        print(f"Error updating assignment: {e}")
