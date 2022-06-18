#nowarn "0025"
let [| N; Y |] = stdin.ReadLine().Split() |> Array.map int

let answers =
    seq {
        for i in 0..N do
            for j in 0 .. N - i do
                let k = N - (i + j)

                if 10000 * i + 5000 * j + 1000 * k = Y then
                    i, j, k
    }

answers
|> Seq.tryHead
|> Option.defaultValue (-1, -1, -1)
|||> printfn "%d %d %d"

// 参考
// https://atcoder.jp/contests/abs/submissions/19157398
// https://atcoder.jp/contests/abs/submissions/6144000
// 再帰ver: https://atcoder.jp/contests/abs/submissions/7474328
