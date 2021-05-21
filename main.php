<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$N] = $integers();
$a = $integers();

$size = min(count($a), 8);
$arraysGroupByRem = array_fill(0, 200, []);

for ($bit = 1; $bit < (1 << $size); $bit++) {
  $indexes = [];
  $rem = 0;
  for ($i = 0; $i < $size; $i++) {
    if ($bit >> $i & 1) {
      $indexes[] = $i + 1;
      $rem = ($rem + $a[$i]) % 200;
    }
  }
  $arraysGroupByRem[$rem][] = $indexes;
}

foreach ($arraysGroupByRem as $rem => $arrays) {
  if (count($arrays) >= 2) {
    $printn("Yes");
    echo count($arrays[0]) . ' ';
    $printn(implode(" ", $arrays[0]));
    echo count($arrays[1]) . ' ';
    $printn(implode(" ", $arrays[1]));
    exit;
  }
}
$printn("No");
