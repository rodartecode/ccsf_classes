$(document).ready(function() {
	$("#flip").click(function() {
		$("#instructions").slideToggle("slow");
	});

	$("#form_avg").on("input", function() {
		console.log("huh");
		let input = $(this);
		let val = $(this).val();

		if (val <= 100 && val >= 0) {
			input.removeClass("invalid").addClass("valid");
		} else {
			input.removeClass("valid").addClass("invalid");
		}
	});

	$("#form_midterm").on("input", function() {
		let input = $(this);
		let val = $(this).val();

		if (val <= 100 && val >= 0) {
			input.removeClass("invalid").addClass("valid");
		} else {
			input.removeClass("valid").addClass("invalid");
		}
	});

	$("#form_final").on("input", function() {
		let input = $(this);
		let val = $(this).val();

		if (val <= 100 && val >= 0) {
			input.removeClass("invalid").addClass("valid");
		} else {
			input.removeClass("valid").addClass("invalid");
		}
	});

	$("#form_acr").on("input", function() {
		let input = $(this);
		let val = $(this).val();

		if (val <= 100 && val >= 0) {
			input.removeClass("invalid").addClass("valid");
		} else {
			input.removeClass("valid").addClass("invalid");
		}
	});
});

function processPage() {
	let average, midterm, final, acr, grade;
	let resultHtml = "";
	let result = document.getElementById("result");

	var form_data = $("#form").serializeArray();
	var error_free = true;
	for (var input in form_data) {
		var element = $("#form_" + form_data[input]["name"]);
		var valid = element.hasClass("valid");
		var error_element = $("span", element.parent());
		if (!valid) {
			error_element.removeClass("error").addClass("error_show");
			error_free = false;
		} else {
			error_element.removeClass("error_show").addClass("error");
		}
	}

	if (!error_free) {
		event.preventDefault();
	} else {
		result.style.display = "block";

		average = parseInt(document.getElementById("form_avg").value);
		midterm = parseInt(document.getElementById("form_midterm").value);
		final = parseInt(document.getElementById("form_final").value);
		acr = parseInt(document.getElementById("form_acr").value);

		grade = parseInt(0.5 * average + 0.2 * midterm + 0.2 * final + 0.1 * acr);

		if (grade < 70) {
			resultHtml = `<div>Student must retake the course.</div>`;
		} else {
			let letter;
			if (grade < 80) {
				letter = "C";
			} else if (grade < 90) {
				letter = "B";
			} else {
				letter = "A";
			}
			resultHtml = `<div>Student passed with a ${letter}</div>`;
		}

		result.innerHTML = resultHtml;
		resultHTML = "";
	}
}

function clearPage() {
	let result = document.getElementById("result");
	result.innerHTML = "";
	result.style.display = "none";

	$("#form div")
		.children("input")
		.removeClass("invalid")
		.removeClass("valid");

	$("#form div")
		.children("span")
		.removeClass("error_show")
		.addClass("error");
}
