<!DOCTYPE html>
<html lang="en">
<head>
<title>Using PHP function</title>
<style type="text/css">
	h3 {color:#FF0000; font-type:italic; text-align:center;}
</style>
</head>
<body>

<p>This paragraph will be shown right before any of the PHP below</p>
<?php
if(isset($_GET['go'])){
     $username = $_GET['name'];
     echo ("<h3>");
    echo ("Hi, $username");
    echo ("</h3>");
}
?>

 <form method="get">
 <label for="name">Your Name </label>
<input type="text" id="name" name="name">
 <input type="submit" name="go" value="Submit" method="get">
 </form>

</body>
</html>