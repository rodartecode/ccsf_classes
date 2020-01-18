var level = 2;
var min = 1;
var answer;
var wrongAudio;
var correctAudio;
var getLevel = lvl => lvl - 1;

function initialize() {
	let quizBox = document.getElementById("quiz-box");
	quizBox.id = "quiz";
	let section = document.createElement("section");
	section.classList.add("center-box");

	let header = document.createElement("h3");
	let headerText = document.createTextNode("Welcome to the Multiplication Quiz");
	header.appendChild(headerText);
	header.id = "quiz-header";

	let par = document.createElement("p");
	parText = document.createTextNode("Are you ready to play?");
	par.appendChild(parText);
	par.id = "quiz-text";

	let but1 = document.createElement("input");
	but1.type = "button";
	but1.value = "Yes";
	but1.addEventListener("click", confirmYes);

	let but2 = document.createElement("input");
	but2.type = "button";
	but2.value = "No";
	but1.addEventListener("click", confirmNo);

	let article = document.createElement("article");
	article.classList.add("input-box");
	article.id = "input-box";

	let lb = document.createElement("br");

	section.appendChild(header);
	section.appendChild(lb);
	section.appendChild(lb);
	article.appendChild(par);
	article.appendChild(lb);
	article.appendChild(but1);
	article.appendChild(but2);
	section.appendChild(article);

	quizBox.appendChild(section);

	wrongAudio = document.getElementById("wrongAudio");
	correctAudio = document.getElementById("correctAudio");
}

function confirmYes() {
	let input = document.getElementById("input-box");
	input.removeChild(input.childNodes[2]);
	input.removeChild(input.childNodes[2]);

	let numForm = document.createElement("input");
	numForm.type = "number";
	numForm.id = "guess";
	numForm.addEventListener("click", m);
	numForm.defaultValue = "0";

	let but3 = document.createElement("input");
	but3.type = "button";
	but3.value = "Submit";
	but3.addEventListener("click", guess);

	input.appendChild(numForm);
	input.appendChild(but3);

	newLevel();
}

function confirmNo() {}

function guess() {
	if (document.getElementById("guess").value == answer) {
		console.log("correct");
		correctAudio.play();
		level++;
		if (document.getElementById("wrong-box")) {
			let input = document.getElementById("input-box");
			input.removeChild(input.childNodes[4]);
		}
		playAgain();
	} else {
		console.log("incorrect");
		wrongAudio.play();
		if (!document.getElementById("wrong-box")) {
			let numForm = document.getElementById("guess");
			numForm.value = 0;

			let input = document.getElementById("input-box");

			let wrongBox = document.createElement("aside");
			wrongBox.classList.add("center-box");
			wrongBox.id = "wrong-box";
			wrongBox.textContent = "Sorry, that's not right.";

			input.append(wrongBox);
		} else {
			let numForm = document.getElementById("guess");
			numForm.value = 0;
		}
	}
}

function playAgain() {
	let text = document.getElementById("quiz-text");
	text.textContent = "That's right!";

	let input = document.getElementById("input-box");
	let par = document.createElement("p");
	parText = document.createTextNode("Try the next level?");
	par.appendChild(parText);
	par.id = "result-text";

	let but1 = document.createElement("input");
	but1.type = "button";
	but1.value = "Yes";
	but1.addEventListener("click", againYes);

	let but2 = document.createElement("input");
	but2.type = "button";
	but2.value = "No";
	but2.addEventListener("click", againNo);

	input.removeChild(input.childNodes[2]);
	input.removeChild(input.childNodes[2]);
	input.appendChild(par);
	input.appendChild(but1);
	input.appendChild(but2);
}

function againYes() {
	let input = document.getElementById("input-box");
	input.removeChild(input.childNodes[2]);
	input.removeChild(input.childNodes[2]);
	input.removeChild(input.childNodes[2]);

	let numForm = document.createElement("input");
	numForm.type = "number";
	numForm.id = "guess";
	numForm.addEventListener("click", m);
	numForm.defaultValue = "0";

	let but3 = document.createElement("input");
	but3.type = "button";
	but3.value = "Submit";
	but3.addEventListener("click", guess);

	input.appendChild(numForm);
	input.appendChild(but3);

	newLevel();
}

function againNo() {
	let header = document.getElementById("quiz-header");
	header.textContent = "Thanks for playing!";
	let text = document.getElementById("quiz-text");
	text.textContent = "";
	let input = document.getElementById("input-box");
	input.removeChild(input.childNodes[2]);
	input.removeChild(input.childNodes[2]);
	input.removeChild(input.childNodes[2]);
}

function newLevel() {
	let header = document.getElementById("quiz-header");
	let text = document.getElementById("quiz-text");
	let form = document.getElementById("guess");

	let number1 = getRndInteger(min, level);
	let number2 = getRndInteger(min, level);
	answer = parseInt(number1 * number2);

	header.textContent = `Welcome to level ${getLevel(level)}`;
	text.textContent = `What is ${number1} times ${number2}?`;
	form.value = "0";
}

function getRndInteger(min, max) {
	let num = Math.floor(Math.random() * max) + min;

	if (max >= 10) {
		num *= Math.floor(Math.random() * 2) == 1 ? 1 : -1;
	}

	return num;
}

function m() {
	console.log("m");
	let el = document.getElementById("guess");

	if (el.defaultValue == el.value) el.value = "";
}
