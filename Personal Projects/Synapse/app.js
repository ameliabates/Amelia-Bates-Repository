let checkboxStates = JSON.parse(localStorage.getItem('checkboxStates')) || {};
let notes = JSON.parse(localStorage.getItem('notes')) || {};


const notesTextareas = document.querySelectorAll('textarea');
notesTextareas.forEach((textarea) => {
    if (textarea.placeholder === "Type your notes here..." && notes.textarea) {
        textarea.value = notes.textarea;
    }
});

// Update checkboxes based on saved states
document.getElementById("checkbox1").checked = checkboxStates["Survey"] || false;
document.getElementById("checkbox2").checked = checkboxStates["Question"] || false;
document.getElementById("checkbox3").checked = checkboxStates["Read"] || false;
document.getElementById("checkbox4").checked = checkboxStates["Reflect"] || false;
document.getElementById("checkbox5").checked = checkboxStates["Review"] || false;

// Event listener to save checkbox states
document.querySelectorAll("input[type=checkbox]").forEach((checkbox) => {
    checkbox.addEventListener("change", (event) => {
        checkboxStates[event.target.value] = event.target.checked;
        localStorage.setItem('checkboxStates', JSON.stringify(checkboxStates));
    });
});

// Event listener to save notes when typing
notesTextareas.forEach((textarea) => {
    if (textarea.placeholder === "Type your notes here...") {
        textarea.addEventListener("input", () => {
            notes.textarea = textarea.value;
            localStorage.setItem('notes', JSON.stringify(notes));
        });
    }
})
// Event listener to generate flashcards
document.getElementById("myButton").addEventListener("click", function () {
    window.location.href = "flashcard.html";
});

// Fetch stored questions and answers from localStorage or initialize as empty
let questionsArray = JSON.parse(localStorage.getItem('questions')) || [];
let answersObject = JSON.parse(localStorage.getItem('answers')) || {};

function addQuestion() {
    const questionInput = document.getElementById('questionInput');
    const answerInput = document.getElementById('answerInput');

    if (questionInput.value.trim() !== '' && answerInput.value.trim() !== '') {
        // Add the question to the array
        const question = questionInput.value.trim();
        questionsArray.push(question);

        // Save the answer for the question in the answers object
        answersObject[question] = answerInput.value.trim();

        // Save updated questions and answers to localStorage
        localStorage.setItem('questions', JSON.stringify(questionsArray));
        localStorage.setItem('answers', JSON.stringify(answersObject));

        // Clear input fields
        questionInput.value = '';
        answerInput.value = '';

        alert('Question and answer saved!');
    } else {
        alert('Please enter both a question and an answer.');
    }
}

// Function to allow the switching of tabs (Checklist, Q&A, Notes)
function openTab(evt, tabName) {
    const tabcontent = document.getElementsByClassName("tabcontent");
    const tablinks = document.getElementsByClassName("tablinks");

    for (let i = 0; i < tabcontent.length; i++) {
        tabcontent[i].classList.remove("active");
    }

    for (let i = 0; i < tablinks.length; i++) {
        tablinks[i].classList.remove("active");
    }

    document.getElementById(tabName).classList.add("active");
    evt.currentTarget.classList.add("active");
}

const urlParams = new URLSearchParams(window.location.search);
const uploadedFile = urlParams.get('file');
const pdfDisplay = document.getElementById('pdfDisplay');
const noPdfMessage = document.getElementById('noPdfMessage');

if (uploadedFile) {
    localStorage.setItem('lastPdf', uploadedFile); // Save the last uploaded file in localStorage
    pdfDisplay.src = uploadedFile;
    pdfDisplay.style.display = "block";
    noPdfMessage.style.display = "none";
} else {
    const lastPdf = localStorage.getItem('lastPdf');
    if (lastPdf) {
        pdfDisplay.src = lastPdf;
        pdfDisplay.style.display = "block";
        noPdfMessage.style.display = "none";
    }
}
function downloadData() {
    const data = {
        notes,
        questions_answers: questionsArray.map(question => ({
            question: question,
            answer: answersObject[question] || ''
        }))
    };

    const blob = new Blob([JSON.stringify(data, null, 2)], { type: 'application/txt' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = 'synapse_data.txt'; // You can change the filename if needed
    a.click();
    URL.revokeObjectURL(url);
}
function clearData() {
    localStorage.clear(); // Clear all data from localStorage

    // Optionally, reset the page UI to reflect the cleared state (like resetting checkboxes and textareas)
    document.querySelectorAll("input[type=checkbox]").forEach((checkbox) => {
        checkbox.checked = false;
    });

    document.querySelectorAll("textarea").forEach((textarea) => {
        textarea.value = '';
    });

    alert('All data has been cleared!');
}