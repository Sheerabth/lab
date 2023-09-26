import re

def analyze_content(content: str) -> dict:
    result = {
        "alphabets": 0,
        "digits": 0,
        "spaces": 0,
        "special_characters": 0,
        "lines": content.count("\n") + 1,
        "words": len(content.split()),
    }
    for char in content:
        if char.isalpha():
            result["alphabets"] += 1
        elif char.isdigit():
            result["digits"] += 1
        elif char.isspace():
            result["spaces"] += 1
        elif char.isascii():
            result["special_characters"] += 1
    return result

def analyze_file(file_path: str) -> None:
    content = ""
    with open(file_path) as file:
        content = file.read()

    print(analyze_content(content))

if __name__ == "__main__":
    analyze_file("pcd/ps1/files/ps1_02.txt")