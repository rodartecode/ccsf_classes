function celsius(fahr) {
    return (5/9) * (parseInt(fahr) - 32);
}

function fahrenheit(cel) {
    return ((9/5) * parseInt(cel) + 32);
}

function processCel() {
	let cel = document.getElementById("cel_cel").value;
	let cel_fahr = document.getElementById("cel_fahr");
	let result = fahrenheit(cel);
	cel_fahr.value = result;

}

function processFahr() {
	let fahr = document.getElementById("fahr_fahr").value;
	let fahr_cel = document.getElementById("fahr_cel");
	let result = celsius(fahr);
	fahr_cel.value = result;

}

function clearFahr() {
	let fahr = document.getElementById("fahr_fahr");
	let fahr_cel = document.getElementById("fahr_cel");
	fahr.value = "32";
	fahr_cel.value = "0";

}

function clearCel() {
	let cel = document.getElementById("cel_cel");
	let cel_fahr = document.getElementById("cel_fahr");
	cel.value = "0";
	cel_fahr.value = "32";

}
