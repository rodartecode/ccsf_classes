var script = document.createElement('script');
script.src = "https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js";
script.type = 'text/javascript';
document.getElementsByTagName('head')[0].appendChild(script);

let dollar, pound, canDollar, euro, yen, peso;

pound = 0.77521;
canDollar = 1.34461;
euro = 0.88754;
yen = 109.350;
peso = 18.2806;



function processPage() {
    dollar = parseFloat(document.getElementById("dollar").value);

    if (dollar !== null) {
        $(document).ready(function () {
            let result;
            let tdClass;
                $("table tr").each(function (i) {
                    $(this).children("td").each(function () {
                        tdClass = $(this).attr('class');

                        switch (tdClass) {
                            case 'brit':
                                result = (dollar * pound).toFixed(2);
                                $(this).text(result);
                                break;
                            case 'can':
                                result = (dollar * canDollar).toFixed(2);
                                $(this).text(result);
                                break;
                            case 'euro':
                                result = (dollar * euro).toFixed(2);
                                $(this).text(result);
                                break;
                            case 'yen':
                                result = (dollar * yen).toFixed(2);
                                $(this).text(result);
                                break;
                            case 'mex':
                                result = (dollar * peso).toFixed(2);
                                $(this).text(result);
                                break;
                        }
                });
            });
        });
    }
}
