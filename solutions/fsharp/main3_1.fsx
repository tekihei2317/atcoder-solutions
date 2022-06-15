stdin.ReadLine()

let rec calculate num =
    if num % 2 = 0 then
        1 + calculate (num / 2)
    else
        0

stdin.ReadLine().Split()
|> Array.map int
|> Array.map calculate
|> Array.min
|> stdout.WriteLine
