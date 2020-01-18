for (var i = 5, product = 1, sum = 0; i < 21; i += 3) {
	product *= i;
	sum += i;
}

var stopper = false;
var bProduct = 1;
var bSum = 0;
var iterator = -1;
while (stopper === false) {
	iterator += 4;
	if (iterator < 32) {
		bProduct *= iterator;
		bSum += iterator;
	} else {
		stopper = true;
	}
}

console.log("product: " + product);
console.log("sum: " + sum);

console.log("Bproduct: " + bProduct);
console.log("Bsum = " + bSum);

function initialize() {
	initTab1();
	initTab2();
	initTab3();

	$(document).ready(function() {
		console.log("ready");

		$("#size").on("input", function() {
			console.log("in size");
			let input = $(this);
			let val = input.val();

			if (val <= 10 && val >= 2) {
				input.removeClass("invalid").addClass("valid");
			} else {
				input.removeClass("valid").addClass("invalid");
			}
		});
	});
}

function initTab1() {
	let tab1a = document.getElementById("p10");
	let tab1b = document.getElementById("p11");
	let tab1c = document.getElementById("p12");
	let tab1d = document.getElementById("p13");

	tab1a.textContent = `The product of 5 * 8 * 11 * 14 * 17 * 20 is ${product}`;
	tab1b.textContent = `The sum of 5 * 8 * 11 * 14 * 17 * 20 is ${sum}`;

	tab1c.textContent = `The product of 3 * 7 * 11 * 15 * 19 * 23 * 27 * 31 is ${bProduct}`;
	tab1d.textContent = `The sum of 3 * 7 * 11 * 15 * 19 * 23 * 27 * 31 is ${bSum}`;
}

function initTab2() {
	let tab2 = document.getElementById("tabs-2");
	let arr = [];
	let rates = [0.05, 0.06, 0.07, 0.08, 0.09, 0.1];
	let sec = document.createElement("section");

	for (let i = 0; i < 6; i++) {
		arr[i] = document.createElement("article");
		arr[i].classList.add("center-box");

		let total = 1000;

		let table = document.createElement("table");
		let head = table.createTHead(0);
		let headRow = head.insertRow(0);
		let head1 = headRow.insertCell(0);
		let head2 = headRow.insertCell(1);
		let head3 = headRow.insertCell(2);

		let body = table.createTBody();

		head.id = "table-header";
		console.log("added");
		head1.textContent = `Year`;
		head2.textContent = `Amount on deposit`;
		head3.textContent = `Interest Rate`;
		for (let j = 0; j < 5; j++) {
			let row = body.insertRow(j);

			let yearCell = row.insertCell(0);
			let depCell = row.insertCell(1);
			let intCell = row.insertCell(2);
			let interest = total * rates[i];
			total += interest;

			yearCell.textContent = `${j + 1}`;
			depCell.textContent = `${total.toFixed(2)}`;
			intCell.textContent = `${rates[i].toFixed(2)}`;
		}
		arr[i].appendChild(table);
		sec.appendChild(arr[i]);
	}

	console.log(sec);
	tab2.appendChild(sec);
}

function initTab3() {
	let tab3 = document.getElementById("tabs-3");
	let sec = document.createElement("section");
	sec.classList.add("center-box");

	let form = document.createElement("form");
	let input = document.createElement("input");
	let label = document.createElement("label");
	let submit = document.createElement("input");
	let reset = document.createElement("input");
	let result = document.createElement("article");
	result.classList.add("center-box");

	form.setAttribute("action", "javascript:void(0);");
	form.setAttribute("onsubmit", "eval()");
	input.setAttribute("type", "number");
	input.setAttribute("id", "size");
	input.setAttribute("defaultValue", "2");
	label.setAttribute("for", "size");
	label.textContent = "Enter a size between 2-10:";
	submit.setAttribute("type", "submit");
	reset.setAttribute("type", "reset");
	reset.setAttribute("onclick", "resetTab()");
	result.setAttribute("id", "result");

	form.appendChild(label);
	form.appendChild(input);
	form.appendChild(submit);
	form.appendChild(reset);

	sec.appendChild(form);
	sec.appendChild(result);
	tab3.appendChild(sec);
}

function compound(years, rate) {
	let p = 1000;
	let r = parseFloat(rate);
	let n = parseInt(years);
	let pow = Math.pow(parseFloat(1 + r), n);
	console.log(pow);
	let a = p * pow;
	return a.toFixed(2);
}

function eval() {
	console.log("EVAL");

	let size = document.getElementById("size").value;
	console.log(size);
	let sizeEl = document.getElementById("size");
	let result = document.getElementById("result");
	let box = document.getElementById("box");
	if (box === null) {
		box = document.createElement("pre");
		box.setAttribute("id", "box")
	}
	else {
		box.innerHTML = "";
	}
	let error_free = true;
	valid = sizeEl.classList.contains("valid");
	if (!valid) {
		console.log("invalid");
		error_free = false;
	}

	if (!error_free) {
		console.log("double invalid");
		event.preventDefault();
	} else {
		console.log("valid");
		result.style.display = "block";
		for (let i = 0; i < 3; i++) {
			if (i == 0) {
				console.log("1");
				for (let j = 0; j < size; j++) {
					console.log("1");
					box.innerHTML += `* `;
				}
				box.innerHTML += '\n';
			} else if (i == 2) {
				console.log("3");
				for (let k = 0; k < size; k++) {
					console.log("3");
					box.innerHTML += `* `;
				}
				box.innerHTML += '\n';
			} else {
				console.log("2");
				for (let m = 0; m < size - 2; m++) {
					box.innerHTML += `* `;
					for (let l = 0; l < size - 2; l++) {
						console.log("2");
						box.innerHTML += `  `;
					}
					box.innerHTML += `* `;
					box.innerHTML += '\n';

				}
			}
		}
	}
	result.appendChild(box);
}

function resetTab() {
	console.log("reset");
	let size = document.getElementById("size").value;
	let result = document.getElementById("result");
	console.log(size);
	let box = document.getElementById("box");
	if (box !== null) {
		console.log("reset");
		box.innerHTML = "";
	}
	result.style.display = "none";
	size = "";
}
