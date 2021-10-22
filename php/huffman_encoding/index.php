<?php
  require_once("entropy.php");

  if (isset($_POST["txt"])) {
    $txt = $_POST["txt"];
    var_dump(calculate_entropy($txt));
  }
?>

<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
  </head>
  <body>
    <form action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
      <textarea name="txt" id="" cols="30" rows="10"></textarea>
      <input type="submit" name="submit" value="ok">
    </form>
  </body>
</html>