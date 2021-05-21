<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$N] = $integers();
$mounts = [];
for ($i = 0; $i < $N; $i++) {
  [$s, $t] = fscanf(STDIN, "%s%d");
  $mounts[$t] = $s;
}

krsort($mounts);
$answer = '';
$count = 0;
foreach ($mounts as $height => $name) {
  $count++;
  if ($count === 2) {
    $answer = $name;
    break;
  }
}
$printn($answer);
