<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

$a = $integers();
sort($a);
if ($a[1] - $a[0] === $a[2] - $a[1]) {
  $printn("Yes");
} else {
  $printn("No");
}
