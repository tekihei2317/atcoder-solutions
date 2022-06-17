let N = stdin.ReadLine() |> int

[ for _ in 1..N -> stdin.ReadLine() |> int ]
|> List.distinct
|> List.length
|> stdout.WriteLine
