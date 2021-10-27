<?php

/* trie le tableau de tableaux associatifs $a alphanumériquement en fonction
 * de la valeur de l'élément de clé $key, modifie le tableau $arr
 * (passage par référence).
 */
function key_sort(&$arr, $key) {
   $cmp = function($arr, $b) use ($key) { return (strcmp($arr[$key], $b[$key])); };

   usort($arr, $cmp);
}


