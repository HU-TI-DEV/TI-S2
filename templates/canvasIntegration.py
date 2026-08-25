from __future__ import annotations

import os
from typing import Any, Dict

from canvasapi import Canvas
from canvasapi.assignment import Assignment
from canvasapi.course import Course
from canvasapi.paginated_list import PaginatedList

from metadataLoader import loadMetadata


def createCanvasClient(metadata: Dict[str, Any]) -> Canvas:
	token = os.getenv("CANVAS_API_TOKEN")
	if not token:
		raise ValueError("Set CANVAS_API_TOKEN in your environment")
	return Canvas(metadata["baseURL"].rstrip("/"), token)

def getCanvasExercises(courseObj: Course) -> PaginatedList[Assignment]:
    return courseObj.get_assignments()

def updateAssignmentDescription(assignmentObj: Assignment, newData: dict) -> Assignment:
    if not isinstance(newData, dict) or "description" not in newData or len(newData) != 1:
        raise ValueError("newData must be a dictionary containing only the 'description' field")
    assignmentObj.edit(assignment=newData)
    return assignmentObj

def getDueDate(assignmentObj: Assignment) -> str:
	return assignmentObj.due_at

if __name__ == "__main__":
	"""
	NOTE: This file should not be run as a standalone script, it is intended to be imported and used as a module. 
	The following code is just for quick testing purposes.
	"""
	meta = loadMetadata()
	canvas = createCanvasClient(meta)
	course = canvas.get_course(meta["courseID"])
	print(f"Connected to course: {course.name} ({meta['courseID']})")

