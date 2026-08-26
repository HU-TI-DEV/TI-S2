"""
This doesn't require actual GitHub integration if ran from a local machine
"""

from pathlib import Path
import subprocess


# Stolen and adapted from https://gist.github.com/elfsternberg/ebfd7b9fdc4e124b04f84f89cf336cdb
# Gets root of the git repository, or raises an OSError if not in a git repo
def get_root() -> Path:
    result = subprocess.run(
        ["git", "rev-parse", "--show-toplevel"],
        check=True,
        capture_output=True,
        text=True,
    )
    root = result.stdout.strip()
    if not root:
        raise OSError(2, "file not found (no git root detected)")
    return Path(root)

# Given a specific opdrachtnaam, find the right .md file in the opdrachten folder or its subfolders
def findMarkdownFile(opdrachtnaam: str) -> Path:
    ROOT_PATH = get_root()
    for md_file in ROOT_PATH.rglob("opdrachten/**/*.md"):
        if md_file.stem == opdrachtnaam:
            return md_file
    raise FileNotFoundError(f"No markdown file found for opdrachtnaam: {opdrachtnaam}")

def getGithubURL(opdrachtnaam: str) -> str:
    # Using the metadata.json file to get the base URL
    import json
    from urllib.parse import quote
    ROOT_PATH = get_root()
    metadata_path = ROOT_PATH / "scripts" / "metadata.json"

    with metadata_path.open("r", encoding="utf-8") as f:
        metadata = json.load(f)

    # Use base URL to construct the GitHub URL for the specific opdrachtnaam
    base_url = metadata[0]["githubRepoURL"]
    base_branch = metadata[0]["githubBranch"]

    # Find location of the opdracht markdown file relative to the root
    md_file_path = findMarkdownFile(opdrachtnaam)
    relative_path = md_file_path.relative_to(ROOT_PATH)

    # Normalize to forward slashes and percent-encode spaces/special chars
    encoded_path = quote(str(relative_path).replace("\\", "/"), safe="/")

    # Construct the GitHub URL
    github_url = f"{base_url}/blob/{base_branch}/{encoded_path}"

    return github_url

# Remove comments in the <!-- comment --> format
def preprocessMarkdown(content: str) -> str:
    import re
    content = re.sub(r'<!--.*?-->', '', content, flags=re.DOTALL)

    return content.strip()

# Given an opdrachtnaam, extract the examination info from the corresponding markdown file
def extractExaminationInfo(opdrachtnaam: str) -> str:
    md_file_path = findMarkdownFile(opdrachtnaam)
    with md_file_path.open("r", encoding="utf-8") as f:
        content = f.read()

    # Extract all text under ## Opleveren
    opleveren_section = content.split("## Opleveren")
    if len(opleveren_section) < 2:
        raise ValueError(f"Opleveren section not found in {md_file_path}")

    opleveren_section = preprocessMarkdown(opleveren_section[1])

    # Add the GitHub URL to the opleveren_section
    github_url = getGithubURL(opdrachtnaam)
    opleveren_section = f"Opdracht link: [{opdrachtnaam}]({github_url})" + "\n\n" + opleveren_section

    return opleveren_section

# Translate the extracted examination info into HTML format for Canvas
def translateToHTML(examination_info: str) -> str:
    from markdown_it import MarkdownIt
    md = MarkdownIt()
    html_content = md.render(examination_info)
    return html_content

# Given an opdrachtnaam, return the examination info in HTML format for Canvas in the way the Canvas API expects, including the Github link
def getExaminationInfo(opdrachtnaam: str) -> dict:
    examination_info = extractExaminationInfo(opdrachtnaam)
    html_info = translateToHTML(examination_info)
    return {"description": html_info}

if __name__ == "__main__":
    """
    NOTE: This file should not be run as a standalone script, it is intended to be imported and used as a module. 
    The following code is just for quick testing purposes.
    """
    # Example usage
    opdrachtnaam = "OO - Classes & operatoren"  # Replace with an actual opdrachtnaam
    try:
        info = extractExaminationInfo(opdrachtnaam)
        print(f"Examination info for {opdrachtnaam}:")
        print(info)
        html_info = translateToHTML(info)
        print(f"Translated HTML for {opdrachtnaam}:")
        print(html_info)
    except Exception as e:
        print(f"Error: {e}")
