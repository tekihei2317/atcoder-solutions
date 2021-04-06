<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));

function printn($value)
{
    echo $value . "\n";
}
