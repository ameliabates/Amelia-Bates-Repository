    const flashcard = document.getElementById('flashcard');
    const questionDiv = document.getElementById('question');
    const answerDiv = document.getElementById('answer');
    const prevButton = document.getElementById('prev');
    const nextButton = document.getElementById('next');
    const counter = document.getElementById('counter');

    let questions = JSON.parse(localStorage.getItem('questions')) || [];
    let answers = JSON.parse(localStorage.getItem('answers')) || { };
    let currentIndex = 0;

    function updateFlashcard() {
        flashcard.classList.remove('flipped');
            if (questions.length > 0) {
        questionDiv.textContent = `Q: ${questions[currentIndex]}`;
    answerDiv.textContent = `A: ${answers[questions[currentIndex]] || "No answer provided"}`;
    counter.textContent = `${currentIndex + 1} / ${questions.length}`;
            } else {
        questionDiv.textContent = "No questions available";
    answerDiv.textContent = "";
    counter.textContent = "0 / 0";
            }
    prevButton.disabled = currentIndex === 0;
    nextButton.disabled = currentIndex === questions.length - 1;
        }

        flashcard.addEventListener('click', () => {
        flashcard.classList.toggle('flipped');
        });

        prevButton.addEventListener('click', () => {
            if (currentIndex > 0) {
        currentIndex--;
    updateFlashcard();
            }
        });

        nextButton.addEventListener('click', () => {
            if (currentIndex < questions.length - 1) {
        currentIndex++;
    updateFlashcard();
            }
        });

    updateFlashcard();

    var el = document.querySelector('.button');

    el.addEventListener('click', function () {
        const lastPdf = localStorage.getItem('lastPdf');
    const redirectUrl = lastPdf ? `index.html?file=${encodeURIComponent(lastPdf)}` : 'index.html';
    window.location.href = redirectUrl;
    });
