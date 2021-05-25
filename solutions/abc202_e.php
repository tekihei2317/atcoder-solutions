<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

class Query
{
  public $depth;
  public $number;
  public $countBefore = 0;
  public $countAfter = 0;

  public function __construct($number, $depth)
  {
    $this->number = $number;
    $this->depth = $depth;
  }
}

class Graph
{
  private $children;
  private $countByDepth;

  public function __construct(int $n, array $children)
  {
    $this->children = $children;
    $this->countByDepth = array_fill(0, $n, 0);
  }

  public function solve(array $queries)
  {
    $this->dfs(0, 0, $queries);
  }

  private function dfs(int $v, int $depth, array $queries)
  {
    foreach ($queries[$v] as $query) {
      // これ元のデータ書き換えられるのかな..?
      $query->countBefore = $this->countByDepth[$query->depth];
    }
    foreach ($this->children[$v] as $child) {
      $this->dfs($child, $depth + 1, $queries);
    }

    $this->countByDepth[$depth]++;
    foreach ($queries[$v] as $query) {
      $query->countAfter = $this->countByDepth[$query->depth];
    }
  }
}

[$N] = $integers();
$p = $integers();
$children = array_fill(0, $N, []);
foreach ($p as $index => $parent) {
  $children[$parent - 1][] = $index + 1;
}


// queries[i]:=頂点iについてのクエリの集合
$queries = array_fill(0, $N, []);
[$Q] = $integers();
for ($i = 0; $i < $Q; $i++) {
  [$u, $d] = $integers();
  $u--;
  $queries[$u][] = new Query($i, $d);
}

$graph = new Graph($N, $children);
$graph->solve($queries);

$answer = array_fill(0, $Q, null);
for ($i = 0; $i < $N; $i++) foreach ($queries[$i] as $query) {
  $answer[$query->number] = $query->countAfter - $query->countBefore;
}
$printn(implode("\n", $answer));
