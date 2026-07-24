from __future__ import annotations

import json
from pathlib import Path
from typing import Any, Dict

METADATA_PATH = Path(__file__).with_name("metadata.json")

def loadMetadata(path: Path = METADATA_PATH) -> Dict[str, Any]:
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

if __name__ == "__main__":
	"""
	NOTE: This file should not be run as a standalone script, it is intended to be imported and used as a module.
	The following code is just for quick testing purposes.
	"""
	meta = loadMetadata()
	print(meta)
