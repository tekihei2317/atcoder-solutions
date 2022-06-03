let n = stdin.ReadLine()
let numbers = stdin.ReadLine().Split() |> Array.map int

let rec calculate num =
    if num % 2 <> 0 then
        0
    else
        calculate (num / 2) + 1

numbers
|> Array.map calculate
|> Array.min
|> stdout.WriteLine
