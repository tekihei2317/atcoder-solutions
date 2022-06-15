let a = stdin.ReadLine() |> int
let b = stdin.ReadLine() |> int
let c = stdin.ReadLine() |> int
let x = stdin.ReadLine() |> int

let mutable ans = 0

for i = 0 to a do
    for j = 0 to b do
        for k = 0 to c do
            if 500 * i + 100 * j + 50 * k = x then
                ans <- ans + 1

ans |> stdout.WriteLine

// TODO: これを参考にする
// https://atcoder.jp/contests/abs/submissions/23686988
