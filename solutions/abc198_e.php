<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

class Graph
{
  private $N;
  private $M;
  private $list;

  public function __construct(int $N, int $M)
  {
    $this->N = $N;
    $this->M = $M;
    $this->list = $this->inputAdjacentList($N, $M);
  }

  private $answers = [];
  private $counts;

  public function solve(array $colors)
  {
    $this->counts = array_fill(1, (int)1e5, 0);
    $this->dfs(0, -1, $colors);
    sort($this->answers);

    return $this->answers;
  }

  public function dfs(int $v, int $parent, array $colors)
  {
    $this->counts[$colors[$v]]++;
    if ($this->counts[$colors[$v]] === 1) $this->answers[] = $v + 1;

    foreach ($this->list[$v] as $u) if ($u != $parent) {
      $this->dfs($u, $v, $colors);
    }

    $this->counts[$colors[$v]]--;
  }

  private function inputAdjacentList(int $N, int $M)
  {
    $list = array_fill(0, $N, []);
    for ($i = 0; $i < $M; $i++) {
      [$a, $b] = fscanf(STDIN, "%d%d");
      $list[$a - 1][] = $b - 1;
      $list[$b - 1][] = $a - 1;
    }
    return $list;
  }
}

[$N] = $integers();
$colors = $integers();
$graph = new Graph($N, $N - 1);

$answers = $graph->solve($colors);
$printn(implode("\n", $answers));
