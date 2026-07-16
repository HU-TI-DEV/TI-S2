from __future__ import annotations

import json
import os
from pathlib import Path
from typing import Any, Dict

from canvasapi import Canvas


METADATA_PATH = Path(__file__).with_name("metadata.json")


def load_metadata(path: Path = METADATA_PATH) -> Dict[str, Any]:
	"""Load the first metadata entry with validation.

	Expected shape:
	[
	    {
	        "baseURL": "https://www.canvas.hu.nl/",
	        "courseID": 50260,
	        "exerciseListURL": "...optional..."
	    }
	]
	"""
	if not path.exists():
		raise FileNotFoundError(f"Metadata file not found: {path}")

	with path.open("r", encoding="utf-8") as handle:
		payload = json.load(handle)

	if not isinstance(payload, list) or not payload:
		raise ValueError("metadata.json must contain a non-empty list")

	entry = payload[0]
	if not isinstance(entry, dict):
		raise ValueError("First metadata entry must be an object")

	base_url = str(entry.get("baseURL", "")).strip()
	course_id_raw = entry.get("courseID")

	if not base_url:
		raise ValueError("metadata.json is missing required field: baseURL")
	if course_id_raw is None:
		raise ValueError("metadata.json is missing required field: courseID")

	try:
		course_id = int(course_id_raw)
	except (TypeError, ValueError) as exc:
		raise ValueError("metadata courseID must be an integer") from exc

	return {
		"baseURL": base_url,
		"courseID": course_id,
		"exerciseListURL": str(entry.get("exerciseListURL", "")).strip(),
	}


def createCanvasClient(metadata: Dict[str, Any]) -> Canvas:
	token = os.getenv("CANVAS_API_TOKEN")
	if not token:
		raise ValueError("Set CANVAS_API_TOKEN in your environment")
	return Canvas(metadata["baseURL"].rstrip("/"), token)

def getCanvasExercises(courseObj: Canvas.Course) -> list:
    return courseObj.get_assignments()

def updateAssignmentDescription(assignmentObj: Canvas.Assignment, newData: dict) -> Canvas.Assignment:
    if not isinstance(newData, dict) or "description" not in newData or len(newData) != 1:
        raise ValueError("newData must be a dictionary containing only the 'description' field")
    assignmentObj.edit(newData)
    return assignmentObj


if __name__ == "__main__":
	meta = load_metadata()
	canvas = createCanvasClient(meta)
	course = canvas.get_course(meta["courseID"])
	print(f"Connected to course: {course.name} ({meta['courseID']})")

