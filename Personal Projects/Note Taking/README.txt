Synapse

# README: Synapse: SQ3R Reading Tool

## Project Overview
The Synapse is a web-based application designed to facilitate active reading and comprehension. The application allows users to upload PDF files, interact with their content using the SQ3R methodology (Survey, Question, Read, Reflect, and Review), and create flashcards for effective study and revision.

---

## Features

### Main Page (index.html)
- **PDF Upload**: Users can upload PDF files to the application for viewing and reading.
- **PDF Display**: The uploaded PDF is displayed on the left panel for reference.
- **SQ3R Checklist**: Includes interactive checkboxes to guide users through the SQ3R process.
- **Q&A Section**: Allows users to create and save custom questions and answers based on their reading.
- **Notes Section**: A dedicated area for taking and saving notes.
- **Flashcard Generator**: Users can generate flashcards from their questions and answers for review.

### Flashcard Page (flashcard.html)
- **Interactive Flashcards**: Users can flip cards to view questions and answers.
- **Navigation**: "Next" and "Previous" buttons for sequential navigation through flashcards.
- **Exit to Main Page**: Return to the main page while preserving the last uploaded PDF.

---

## Installation and Setup

### Prerequisites
- A local web server environment (e.g., XAMPP, WAMP, or MAMP).
- A web browser (Google Chrome, Firefox, etc.).


### Steps to Set Up
1. **Install a Local Server**:
   - Install XAMPP, WAMP, or an equivalent web server environment.

2. **Place the Project Files**:
   - Copy the entire project folder into the `htdocs` directory (or equivalent) of your server.

3. **Configure Uploads Directory**:
   - Ensure the `uploads/` directory exists within the project folder.
   - Set write permissions for the directory (on Windows, right-click > Properties > Security > Edit Permissions).

4. **Start the Server**:
   - Launch the server and navigate to the project using `http://localhost/project-folder/` in your web browser.

---

## Usage Instructions

### Uploading and Viewing a PDF
1. Open `index.html` in your web browser.
2. Use the file upload form on the left panel to upload a PDF file.
3. Once uploaded, the PDF will be displayed. The last uploaded PDF will persist until a new file is uploaded.

### Using the SQ3R Checklist
1. Follow the checklist tasks to guide your reading and comprehension.
2. Mark each step as complete using the provided checkboxes.

### Creating Questions and Notes
- Use the **Q&A** tab to add questions and answers based on the reading material.
- Use the **Notes** tab to jot down notes or summarize key points.

### Generating and Reviewing Flashcards
1. Click the "Generate Flashcards" button in the **Checklist** section.
2. Navigate through flashcards on the `flashcard.html` page.
3. Exit the flashcard page using the "X" button to return to the main page.

---

## File Descriptions

### HTML Files
- **index.html**: Main page for the SQ3R Reading Tool.
- **flashcard.html**: Flashcard study page.

### PHP Files
- **upload.php**: Handles the file upload process and stores PDF files in the `uploads/` directory.

### JavaScript Functionality
- Handles local storage for storing the last uploaded PDF.
- Manages user interactions, including navigation, flashcard flipping, and dynamic updates to the interface.

### CSS Files
- Provides styling for the application layout and components.

---

## Local Storage Management
The application uses `localStorage` to:
1. Store the last uploaded PDF file path.
2. Save user-created questions and answers for flashcards.

---

## Troubleshooting

### Common Issues
1. **PDF Not Displaying**:
   - Ensure the `uploads/` directory is writable.
   - Check the file format. Only `.pdf` files are supported.

2. **Flashcards Not Updating**:
   - Verify that questions and answers are being saved in `localStorage`.

3. **Redirect Errors**:
   - Ensure that the `upload.php` script is correctly saving files and updating paths.

---

## Future Enhancements
- Add support for other file formats (e.g., `.txt` or `.docx`).
- Implement user authentication for saving and accessing personalized data.
- Enable server-side storage for uploaded files and flashcards.

---

## License
This project is open-source and can be modified for personal or educational use.

---

## Acknowledgments
- Created using HTML, CSS, JavaScript, and PHP.
- Inspired by the SQ3R reading strategy for effective study habits.

