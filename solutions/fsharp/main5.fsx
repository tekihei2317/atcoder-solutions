#nowarn "0025"
let [| N; A; B |] = stdin.ReadLine().Split() |> Array.map int

let rec digitSum num =
    if num > 0 then
        num % 10 + digitSum (num / 10)
    else
        0

[ 1..N ]
|> List.filter (fun i -> A <= digitSum (i) && digitSum (i) <= B)
|> List.sum
|> stdout.WriteLine
