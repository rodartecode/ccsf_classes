$(document).ready(function() {
	$("#form_first").on("input", function() {
		let input = $(this);
		let val = $(this).val();

		if (val >= 0) {
			input.removeClass("invalid").addClass("valid");
		} else {
			input.removeClass("valid").addClass("invalid");
		}
	});
	$("#form_second").on("input", function() {
		let input = $(this);
		let val = $(this).val();

		if (val >= 0) {
			input.removeClass("invalid").addClass("valid");
		} else {
			input.removeClass("valid").addClass("invalid");
		}
	});
	$("#form_third").on("input", function() {
		let input = $(this);
		let val = $(this).val();

		if (val >= 0) {
			input.removeClass("invalid").addClass("valid");
		} else {
			input.removeClass("valid").addClass("invalid");
		}
	});
	$("#form_fourth").on("input", function() {
		let input = $(this);
		let val = $(this).val();

		if (val >= 0) {
			input.removeClass("invalid").addClass("valid");
		} else {
			input.removeClass("valid").addClass("invalid");
		}
	});
});

function processPage() {
	let first, second, third, fourth;
	let firstResult, secondResult, thirdResult, fourthResult;
	let totalSold, salary;
	let item1 = 239.99;
	let item2 = 129.75;
	let item3 = 99.95;
	let item4 = 350.89;
	let result = document.getElementById("result");
	let form_data = $("#form").serializeArray();

	var error_free = true;
	for (var input in form_data) {
		var element = $("#form_" + form_data[input]["name"]);
		var valid = element.hasClass("valid");
		var error_element = $("span", element.parent());
		if (!valid) {
			error_element.removeClass("error").addClass("error_show");
			error_free = false;
			console.log("error");
		} else {
			error_element.removeClass("error_show").addClass("error");
			console.log("no error");
		}
	}

	if (!error_free) {
		event.preventDefault();
	} else {
		result.style.display = "block";

		first = parseFloat(document.getElementById("form_first").value);
		second = parseFloat(document.getElementById("form_second").value);
		third = parseFloat(document.getElementById("form_third").value);
		fourth = parseFloat(document.getElementById("form_fourth").value);

		firstResult = parseFloat(first * item1).toFixed(2);
		secondResult = parseFloat(second * item2).toFixed(2);
		thirdResult = parseFloat(third * item3).toFixed(2);
		fourthResult = parseFloat(fourth * item4).toFixed(2);
		totalSold = parseFloat(
			parseFloat(firstResult) +
				parseFloat(secondResult) +
				parseFloat(thirdResult) +
				parseFloat(fourthResult)
		).toFixed(2);
		console.log(totalSold);
		let commission = parseFloat(totalSold * 0.09).toFixed(2);
		console.log(commission);
		commission = parseFloat(commission) + parseFloat(200);
		console.log(commission);

		document.getElementById("total_item1").value = firstResult;
		document.getElementById("int_item1").value = first;
		document.getElementById("total_item2").value = secondResult;
		document.getElementById("int_item2").value = second;
		document.getElementById("total_item3").value = thirdResult;
		document.getElementById("int_item3").value = third;
		document.getElementById("total_item4").value = fourthResult;
		document.getElementById("int_item4").value = fourth;
		document.getElementById("final_total").value = totalSold;
		document.getElementById("salary").value = commission;
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
