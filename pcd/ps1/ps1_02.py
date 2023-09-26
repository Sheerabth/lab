from bs4 import BeautifulSoup

def remove_tags(html_text):
    soup = BeautifulSoup(html_text, "html.parser")
    text = soup.get_text()
    return text

def save_to_text_file(text, output_file):
    with open(output_file, "w", encoding="utf-8") as file:
        file.write(text)

def main(input_file, output_file):
    with open(input_file, "r", encoding="utf-8") as file:
        html_text = file.read()

    plain_text = remove_tags(html_text)
    save_to_text_file(plain_text, output_file)
    print("Conversion complete. Text file saved successfully!")

if __name__ == "__main__":
    input_html_file = "pcd/ps1/files/students-menu.html"
    output_text_file = "pcd/ps1/files/ps1_02.txt"
    main(input_html_file, output_text_file)