function processPage() {
    let sum, average, product, smallest, largest;
    let first, second, third;
    let resultHtml = "";
    let result = document.getElementById("result");

    first = parseInt(document.getElementById("first_number").value);
    second = parseInt(document.getElementById("second_number").value);
    third = parseInt(document.getElementById("third_number").value);

    sum = first + second + third;
    average = sum / 3;
    product = first * second * third;
    smallest = Math.min(first, second, third);
    largest = Math.max(first, second, third);

    resultHtml = `SUM: ${sum} <br>
    MEAN: ${average} <br>
    PRODUCT: ${product} <br> 
    SMALLEST: ${smallest} <br>
    LARGEST: ${largest} <br>`;

    result.innerHTML = resultHtml
    resultHTML = "";
}

function clearPage() {
    let result = document.getElementById("result");

    result.innerHTML = "";
}