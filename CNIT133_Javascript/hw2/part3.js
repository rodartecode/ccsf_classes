var script = document.createElement('script');
script.src = "https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js";
script.type = 'text/javascript';
document.getElementsByTagName('head')[0].appendChild(script);

function processPage() {
    let resultHtml = "";
    let result = document.getElementById("result");
    let resultArr = [];
    let negatives = 0;
    let positives = 0;
    let zeroes = 0;

    first = parseInt(document.getElementById("first_number").value);
    second = parseInt(document.getElementById("second_number").value);
    third = parseInt(document.getElementById("third_number").value);
    fourth = parseInt(document.getElementById("fourth_number").value);
    fifth = parseInt(document.getElementById("fifth_number").value);

    resultArr.push(first, second, third, fourth, fifth);
    resultArr.forEach(function (e) {
        if (e < 0) {
            negatives += 1;
        } else if (e > 0) {
            positives += 1;
        } else {
            zeroes += 1;
        }
    })

    resultHtml = `Less than zero: ${negatives}<br>
    Zero: ${zeroes}<br>
    More than zero: ${positives}<br>
    <button>Click to fade numbers</button><br><br>
    `
    result.innerHTML = resultHtml;
    
    $(document).ready(function () {
        $("button").click(function () {
            $("#result").fadeTo("slow", 0.15);
        });
    });
}

function clearPage() {
    let result = document.getElementById("result");

    result.innerHTML = "";
}