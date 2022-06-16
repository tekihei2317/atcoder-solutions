let A = stdin.ReadLine() |> int
let B = stdin.ReadLine() |> int
let C = stdin.ReadLine() |> int
let X = stdin.ReadLine() |> int

seq {
    for i in 0..A do
        for j in 0..B do
            for k in 0..C do
                if 500 * i + 100 * j + 50 * k = X then 1
}
|> (Seq.fold (+) 0)
|> stdout.WriteLine
