<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
        "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
      <html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
<head>
<title>Form using external PHP</title>
<style type="text/css">
	body {background-color:#000000; color:#FFFFFF; font-weight:bold;}
	.underline {text-decoration:underline; color:#FF0000;}
</style>
</head>

<body>
<?php
// Capture the values posted to this php program from the text fields 
// which were named 'Name' and 'DirtyWord' respectively

$name = $_REQUEST['Name'] ; 
$word = $_REQUEST['DirtyWord'] ; 
?>

<p>Hi <?php print($name); ?></p>

<p>You like the word <span class="underline"> <?php print($word); ?>!?!</span></p>

<p>You should be ashamed of yourself!</p>
</body>
</html>