<?php
function calculate_entropy($txt) {
  if (!isset($txt)) return;

  $letters = array_unique(str_split($txt));
  $information_quantities = [];
  $entropy = 0;

  foreach ($letters as $l) {
    $count = substr_count($txt, $l);
    $frequency = $count / strlen($txt);
    $information_quantity = $count > 0 ? $frequency * -log($frequency, 2) : 0;

    $information_quantities[$l] = $information_quantity;
    $entropy += $information_quantity;
  }

  return $entropy;
}
