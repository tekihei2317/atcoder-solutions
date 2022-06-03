#nowarn "0025"
let [| a; b |] = stdin.ReadLine().Split() |> Array.map int

if a * b % 2 = 0 then "Even" else "Odd"
|> stdout.WriteLine
