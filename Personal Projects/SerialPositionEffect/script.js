const WORDS = [
    "time",
    "person",
    "year",
    "way",
    "day",
    "thing",
    "man",
    "world",
    "life",
    "hand", 
    "part",
    "child", 
    "woman", 
    "place", 
    "work", 
    "week", 
    "case",
    "point",
    "government",
    "company",
    "number",
    "group",
    "problem",
    "fact"
    
];

let recalledWords = [];
let intTrials = 0;
let trialResults = [];
let positionData = [0, 0, 0, 0, 0, 0, 0]; // Tracks correct recalls at each position
let currentWords = [];

function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
    return array.slice(0, 7);
}

// Function to display words sequentially with a delay
function displayWordsSequentially(words, delay) {
    return new Promise(async (resolve) => {
        let wordListElement = document.getElementById("wordList");
        wordListElement.innerHTML = ""; // Clear previous content

        for (let i = 0; i < words.length; i++) {
            let li = document.createElement("li");
            li.textContent = words[i];
            wordListElement.appendChild(li);
            await new Promise(resolve => setTimeout(resolve, delay)); // Wait for delay
            wordListElement.removeChild(li); // Remove word after delay
        }

        resolve(); // Resolve the promise after all words have been displayed
    });
}

// Function to handle word submission
function submitWord() {
    let wordInput = document.getElementById("wordInput");
    let word = wordInput.value.trim().toLowerCase();
    let userListElement = document.getElementById("userList");

    if (word !== "" && !recalledWords.includes(word)) {
        recalledWords.push(word);
        let li = document.createElement("li");
        li.textContent = word;
        userListElement.appendChild(li);
    }
    wordInput.value = ""; // Clear input field
}

// Function to compare recalled words with original words
function compareWords() {
    let resultElement = document.getElementById("result");
    let correctWords = recalledWords.filter(word => currentWords.includes(word));
    let missingWords = currentWords.filter(word => !recalledWords.includes(word));

    correctWords.forEach(correctWord => {
        let position = currentWords.indexOf(correctWord); 
        positionData[position]++; 
    });

    intTrials++;
    resultElement.innerHTML = `<p>You recalled ${correctWords.length} out of ${currentWords.length} words correctly.</p>`;
    resultElement.innerHTML += `<p>Correctly recalled words: ${correctWords.join(", ")}</p>`;
    resultElement.innerHTML += `<p>Words you missed: ${missingWords.join(", ")}</p>`;

    document.getElementById("inputContainer").style.display = "none";
    
    document.getElementById("nextButton").style.display = "block";
}

function resetExperiment() {
    if (intTrials < 3) {
    recalledWords = [];
    document.getElementById("userList").innerHTML = "";
    document.getElementById("result").innerHTML = "";
  
    document.getElementById("nextButton").style.display = "none";
    document.getElementById("inputContainer").style.display = "block";

    currentWords = shuffleArray(WORDS);
    displayWordsSequentially(currentWords, 1000)
    }

    else {
        document.getElementById("nextButton").style.display = "none";
        let finishedElement = document.getElementById("result");
        finishedElement.innerHTML = '<p>Experiment Finished. Here are your results:</p>';

        trialResults.forEach(trial => {
            finishedElement.innerHTML += `<p>Trial ${trial.trialNumber}: Correctly recalled words: ${trial.correctWords.join(", ")}, Original order: ${trial.originalOrder.join(", ")}</p>`;
        });;

        displayLineGraph();
    }
}

function displayLineGraph() {
    document.getElementById("userList").style.display = "none";
    let ctx = document.getElementById('performanceChart').getContext('2d');
    new Chart(ctx, {
        type: 'line',
        data: {
            labels: ['1st Position', '2nd Position', '3rd Position', '4th Position', '5th Position', '6th Position', '7th Position'], // Word positions in the sequence
            datasets: [{
                label: 'Correct Recalls by Position',
                data: positionData, 
                borderColor: 'rgba(75, 192, 192, 1)',
                backgroundColor: 'rgba(75, 192, 192, 0.2)',
                fill: true,
                tension: 0.1
            }]
        },
        options: {
            scales: {
                x: {
                    title: {
                        display: true,
                        text: 'Position in Word Sequence'
                    }
                },
                y: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Number of Correct Recalls'
                    }
                }
            }
        }
    });
}


// Add event listener for DOM content loaded
document.addEventListener("DOMContentLoaded", async () => {

    currentWords = shuffleArray(WORDS);
    await displayWordsSequentially(currentWords, 1000); // Display each word for 1 second

    // Create input field and submit button after words have been displayed
    let inputContainer = document.createElement("div");
    inputContainer.id = "inputContainer";
    let wordInput = document.createElement("input");
    wordInput.type = "text";
    wordInput.id = "wordInput";
    wordInput.placeholder = "Enter a word";

    let submitButton = document.createElement("button");
    submitButton.textContent = "Submit";
    submitButton.onclick = submitWord;

    let compareButton = document.createElement("button");
    compareButton.textContent = "Compare";
    compareButton.onclick = compareWords;

    inputContainer.appendChild(wordInput);
    inputContainer.appendChild(submitButton);
    inputContainer.appendChild(compareButton);

    document.body.appendChild(inputContainer);

    let nextButton = document.createElement("button");
    nextButton.textContent = "Next";
    nextButton.id = "nextButton";
    nextButton.style.display = "none"; // Hide the button initially
    nextButton.onclick = resetExperiment;

    document.body.appendChild(nextButton);

    let canvas = document.createElement('canvas');
    canvas.id = 'performanceChart';
    document.body.appendChild(canvas);
});








