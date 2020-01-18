const stateArr = [
	["AL", "Alabama", "Montgomery", "4,779,736"],
	["AK", "Alaska", "Juneau", "710,231"],
	["AZ", "Arizona", "Phoenix", "6,392,017"],
	["AR", "Arkansas", "Little Rock", "2,915,918"],
	["CA", "California", "Sacramento", "37,253,956"],
	["CO", "Colorado", "Denver", "5,029,196"]
];

function initialize() {
	initTab1();
	initTab2();
	initTab3();
}

function initTab1() {
	let tab1 = document.getElementById("tabs-1");
	let sec = document.createElement("section");
	sec.classList.add("center-box");

	let form = document.createElement("form");
	let input = document.createElement("input");
	let label = document.createElement("label");
	let radio1 = document.createElement("input");
	let radio2 = document.createElement("input");
	let radio3 = document.createElement("input");
	let check1 = document.createElement("input");
	let check2 = document.createElement("input");
	let check3 = document.createElement("input");
	let select = document.createElement("select");
	let option1 = document.createElement("option");
	let option2 = document.createElement("option");
	let option3 = document.createElement("option");
	let submit = document.createElement("input");
	let reset = document.createElement("input");

	form.setAttribute("action", "hw5/ty.php");
	form.setAttribute("name", "Form1");
	form.setAttribute("method", "post");
	form.setAttribute("onsubmit", "return eval()");

	input.setAttribute("type", "text");
	input.setAttribute("id", "text");
	input.setAttribute("name", "text");

	label.setAttribute("for", "text");
	label.textContent = "Enter some text: ";

	radio1.setAttribute("type", "radio");
	radio2.setAttribute("type", "radio");
	radio3.setAttribute("type", "radio");
	radio1.setAttribute("name", "radio");
	radio2.setAttribute("name", "radio");
	radio3.setAttribute("name", "radio");
	radio1.setAttribute("value", "Radio 1");
	radio2.setAttribute("value", "Radio 2");
	radio3.setAttribute("value", "Radio 3");

	check1.setAttribute("type", "checkbox");
	check1.setAttribute("value", "Checkbox 1");
	check1.setAttribute("name", "check");
	check2.setAttribute("type", "checkbox");
	check2.setAttribute("value", "Checkbox 2");
	check2.setAttribute("name", "check");
	check3.setAttribute("type", "checkbox");
	check3.setAttribute("value", "Checkbox 3");
	check3.setAttribute("name", "check");

	let option0 = document.createElement("option");
	option0.value = "";
	option0.setAttribute("name", "option");
	option1.value = "Option 1";
	option1.setAttribute("name", "option");
	option2.value = "Option 2";
	option2.setAttribute("name", "option");
	option3.value = "Option 3";
	option3.setAttribute("name", "option");
	select.setAttribute("name", "optionList");
	select.id = "optionList";

	submit.setAttribute("type", "submit");

	reset.setAttribute("type", "reset");
	reset.setAttribute("onclick", "resetTab()");

	option0.innerHTML += "Choose an option";
	option0.classList.add = "required";
	select.appendChild(option0);
	option1.innerHTML += "Option 1";
	select.appendChild(option1);
	option2.innerHTML += "Option 2";
	select.appendChild(option2);
	option3.innerHTML += "Option 3";
	select.appendChild(option3);

	form.appendChild(label);
	form.appendChild(input);
	form.appendChild(document.createElement("br"));
	form.appendChild(radio1);
	form.innerHTML += "Radio 1";
	form.appendChild(document.createElement("br"));
	form.appendChild(radio2);
	form.innerHTML += "Radio 2";
	form.appendChild(document.createElement("br"));
	form.appendChild(radio3);
	form.innerHTML += "Radio 3";
	form.appendChild(document.createElement("br"));
	form.appendChild(check1);
	form.innerHTML += "Check 1";
	form.appendChild(document.createElement("br"));
	form.appendChild(check2);
	form.innerHTML += "Check 2";
	form.appendChild(document.createElement("br"));
	form.appendChild(check3);
	form.innerHTML += "Check 3";
	form.appendChild(document.createElement("br"));
	form.appendChild(select);
	form.appendChild(submit);
	form.appendChild(reset);

	sec.appendChild(form);
	tab1.appendChild(sec);
}

function initTab2() {
	let tab2 = document.getElementById("tabs-2");

	let sec = document.createElement("section");
	sec.classList.add("center-box");

	let header = document.createElement("h1");
	header.textContent = "CHESS DROPDOWNS";

	let header1 = document.createElement("h3");
	header1.textContent = "Using onChange";
	let header2 = document.createElement("h3");
	header2.textContent = "Using onClick";

	let form1 = document.createElement("Form");
	let form2 = document.createElement("Form");

	let select1 = document.createElement("select");
	select1.setAttribute("name", "chessList");
	select1.setAttribute("onChange", "goToPage(this.form)");

	let select2 = document.createElement("select");
	select2.setAttribute("name", "chessList");

	let option0 = document.createElement("option");
	option0.classList.add = "required";
	option0.value = "";
	option0.innerHTML = "Choose an option";
	let option1 = document.createElement("option");
	option1.value = "https://www.chess.com";
	option1.innerHTML = "Chess.com";
	let option2 = document.createElement("option");
	option2.value = "https://www.lichess.org";
	option2.innerHTML = "LiChess.org";
	let option3 = document.createElement("option");
	option3.value = "https://www.chess24.com";
	option3.innerHTML = "Chess24.com";

	let goButton = document.createElement("input");
	goButton.type = "button";
	goButton.value = "Go";
	goButton.setAttribute("onclick", "goToPage(this.form)");

	let clone1 = option1.cloneNode(true);
	let clone2 = option2.cloneNode(true);
	let clone3 = option3.cloneNode(true);

	select1.appendChild(option0);
	select1.appendChild(option1);
	select1.appendChild(option2);
	select1.appendChild(option3);

	select2.appendChild(clone1);
	select2.appendChild(clone2);
	select2.appendChild(clone3);

	form1.appendChild(header1);
	form1.appendChild(select1);
	form2.appendChild(header2);
	form2.appendChild(select2);
	form2.appendChild(goButton);

	sec.appendChild(header);
	sec.appendChild(form1);
	sec.appendChild(form2);

	tab2.appendChild(sec);
}

function initTab3() {
	let tab3 = document.getElementById("tabs-3");

	let sec = document.createElement("section");
	sec.classList.add("center-box");
	let header = document.createElement("h1");
	let form = document.createElement("form");
	let label = document.createElement("label");
	let input = document.createElement("input");
	let submit = document.createElement("input");
	let result = document.createElement("article");

	result.id = "result";
	result.classList.add("center-box");

	header.textContent = "Learn some state facts!";

	form.action = "javascript:void(0);";

	label.textContent = "Enter a state: ";
	label.setAttribute("for", "search");

	input.type = "text";
	input.name = "search";
	input.id = "search";

	submit.type = "submit";
	submit.onclick = function() {
		pageProcess();
	};
	console.log(submit.onclick);
	console.log(submit.type);

	sec.appendChild(header);
	form.appendChild(label);
	form.appendChild(input);
	form.appendChild(submit);
	sec.appendChild(form);
	sec.appendChild(result);

	tab3.appendChild(sec);
}

function resetTab() {
	document.getElementById("text").value = "";
	$("input[name=radio]").attr("checked", false);
	$("input[name=check]").attr("checked", false);

}

function eval() {
	let list = document.getElementById("optionList");
	if (document.getElementById("text").value == "") {
		please();
		return false;
	}
	if ($("input[name=radio]:checked").length == 0) {
		please();
		return false;
	}
	if ($("input[name=check]:checked").length == 0) {
		please();
		return false;
	}
	if (list.selectedIndex == 0) {
		please();
		return false;
	}
}

function please() {
	alert("Please fill out all the form options. It's very important.");
}

function goToPage(aForm) {
	console.log(aForm);
	let destination = aForm.chessList.options[aForm.chessList.selectedIndex].value;
	window.location = destination;
}

function pageProcess() {
	let search = document.getElementById("search").value;
	let result = document.getElementById("result");
	console.log(search);
	if (isValid(search)) {
		console.log("valid");
		result.innerHTML = getStateInfo(getStateIndex(search));
		result.style.display = "block";
	} else {
		result.innerHTML = "Sorry, I can't find that! Try another search phrase.";
		result.style.display = "block";
	}
}

function isValid(t) {
	for (let i = 0; i < stateArr.length; i++) {
		for (let j = 0; j < 2; j++) {
			if (t.toUpperCase() === stateArr[i][j].toUpperCase()) return true;
		}
	}
	console.log("invalid");
}

function getStateIndex(t) {
	if (isValid(t)) {
		for (let i = 0; i < stateArr.length; i++) {
			for (let j = 0; j < 2; j++) {
				if (t.toUpperCase() === stateArr[i][j].toUpperCase()) return i;
			}
		}
	}
}

function getStateInfo(index) {
	let returnHTML = "";
	let factHeader = `<h5>Thanks for your inquiry!</h5> <h7>Here's some facts!</h7>`;
	returnHTML += factHeader;
	let abb = stateArr[index][0];
	let name = stateArr[index][1];
	let cap = stateArr[index][2];
	let pop = stateArr[index][3];

	let par = "<p>";
	par += `The state abbreviation is ${abb}`;
	par += "<br />";
	par += `The state name is ${name}`;
	par += "<br />";
	par += `The capital is ${cap}`;
	par += "<br />";
	par += `The state population is ${pop}`;
	par += "</p>";

	returnHTML += par;

	return returnHTML;
}
