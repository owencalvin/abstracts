<?php

# fonctions atomiques de validation
function longer_than($critere, $valeur) {
   return strlen($valeur) > $critere;
}

function numeric($critere, $valeur) {
   return is_numeric($valeur);
}

function ge($critere, $valeur) {
   return $valeur > $critere;
}

# tableau de validation
$validation_array= [
   'nom' => ['longer_than' => 6],
   'valeur' => [
      'numeric' => 0,
      'ge' => 0
   ]
];

#$params = $_GET;

# pour tester
#$params = ['a' => 'b');
#$params = ['nom' => 'court');
#$params = ['nom' => '1234567');
$params = ['valeur' => -5];
#$params = ['valeur' => 'toto');
#$params = ['valeur' => 42.2);

foreach ($params as $p => $v) {
   $ok = 1;
   if (array_key_exists($p, $validation_array)) {
      # compl�ter :)
   }
   else {
      echo "unknown param: ", $p, "\n";
   }
}


