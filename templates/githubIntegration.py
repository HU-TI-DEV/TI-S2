"""
This doesn't require actual GitHub integration if ran from a local machine
"""

from pathlib import Path

# Get the root path of the project, independent of where this script is located
ROOT_PATH = Path(__file__).resolve().parent.parent

# Given a specific opdrachtnaam, find the right .md file in the opdrachten folder or its subfolders
def findMarkdownFile(opdrachtnaam: str) -> Path:
    for md_file in ROOT_PATH.rglob("opdrachten/**/*.md"):
        if md_file.stem == opdrachtnaam:
            return md_file
    raise FileNotFoundError(f"No markdown file found for opdrachtnaam: {opdrachtnaam}")

def extractExaminationInfo(opdrachtnaam: str) -> dict:
    md_file_path = findMarkdownFile(opdrachtnaam)
    with md_file_path.open("r", encoding="utf-8") as f:
        content = f.read()

    # Extract all text under ## Opleveren
    opleveren_section = content.split("## Opleveren")
    if len(opleveren_section) < 2:
        raise ValueError(f"Opleveren section not found in {md_file_path}")

    return opleveren_section[1].strip()

if __name__ == "__main__":
    # Example usage
    opdrachtnaam = "OO - Classes & operatoren"  # Replace with an actual opdrachtnaam
    try:
        info = extractExaminationInfo(opdrachtnaam)
        print(f"Examination info for {opdrachtnaam}:")
        print(info)
    except Exception as e:
        print(f"Error: {e}")