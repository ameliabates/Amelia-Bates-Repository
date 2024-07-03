document.addEventListener("DOMContentLoaded", async () => {
    const WORDS = [
        "area",
        "book",
    ];

    let recalledWords = [];


    async function displayWordsSequentially(words, delay) {
        let wordListElement = document.getElementById("wordList");
        wordListElement.innerHTML = ""; 

        for (let i = 0; i < words.length; i++) {
            let li = document.createElement("li");
            li.textContent = words[i];
            wordListElement.appendChild(li);
            await new Promise(resolve => setTimeout(resolve, delay)); 
            wordListElement.removeChild(li);
    }


    window.submitWord = function() {
        let wordInput = document.getElementById("wordInput");
        let word = wordInput.value.trim().toLowerCase();
        let feedback = document.getElementById("feedback");

        if (word !== "") {
            recalledWords.push(word);
            wordInput.value = ""; // Clear input field
            feedback.textContent = `You have entered: ${recalledWords.join(", ")}`;
        }
    }

  
    window.compareWords = function() {
        let resultElement = document.getElementById("result");
        let correctWords = recalledWords.filter(word => WORDS.includes(word));
        let missingWords = WORDS.filter(word => !recalledWords.includes(word));

        resultElement.innerHTML = `<p>You recalled ${correctWords.length} out of ${WORDS.length} words correctly.</p>`;
        resultElement.innerHTML += `<p>Correctly recalled words: ${correctWords.join(", ")}</p>`;
        resultElement.innerHTML += `<p>Words you missed: ${missingWords.join(", ")}</p>`;
    }


    await displayWordsSequentially(WORDS, 1000);


    let inputContainer = document.getElementById("inputContainer");
    console.log(inputContainer); 

    if (inputContainer) {
        inputContainer.style.display = "block"; 
    } else {
        console.error("inputContainer not found in the DOM.");
    }
});






