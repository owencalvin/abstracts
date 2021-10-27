<?php

require_once("./products.php");
require_once("./functions.php");

key_sort($products, "id");

var_dump($products);
