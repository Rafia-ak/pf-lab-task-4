let progress = 0;
let lecturesWatched = 0;
let assignmentsSubmitted = 0;

const totalLectures = 2;
const totalAssignments = 2;

function updateProgress() {
    const totalCompleted = (lecturesWatched + assignmentsSubmitted) / (totalLectures + totalAssignments);
    progress = totalCompleted * 100;

    document.getElementById('progress-bar').style.width = `${progress}%`;
    document.getElementById('progress-text').innerText = `${Math.round(progress)}%`;
}

document.getElementById("mark1").addEventListener("click", function () {
    if (!this.classList.contains("watched")) {
        this.classList.add("watched");
        this.innerText = "Watched";
        lecturesWatched++;
        updateProgress();
    }
});

document.getElementById("mark2").addEventListener("click", function () {
    if (!this.classList.contains("watched")) {
        this.classList.add("watched");
        this.innerText = "Watched";
        lecturesWatched++;
        updateProgress();
    }
});

document.getElementById("assignmentForm1").addEventListener("submit", function (event) {
    event.preventDefault();
    const fileInput = document.getElementById("file1");
    const file = fileInput.files[0];
    const submitBtn = document.getElementById("submitBtn1");

    if (file) {
        submitBtn.innerText = "Submitted";
        submitBtn.disabled = true;
        assignmentsSubmitted++;
        updateProgress();
        alert(`You have successfully submitted ${file.name}`);
    } else {
        alert("Please select a file to submit.");
    }
});

document.getElementById("assignmentForm2").addEventListener("submit", function (event) {
    event.preventDefault();
    const fileInput = document.getElementById("file2");
    const file = fileInput.files[0];
    const submitBtn = document.getElementById("submitBtn2");

    if (file) {
        submitBtn.innerText = "Submitted";
        submitBtn.disabled = true;
        assignmentsSubmitted++;
        updateProgress();
        alert(`You have successfully submitted ${file.name}`);
    } else {
        alert("Please select a file to submit.");
    }
});

function scrollToTop() {
    window.scrollTo({
        top: 0,
        behavior: 'smooth'
    });
}

updateProgress();