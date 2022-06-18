let readIntArray = stdin.ReadLine().Split() |> Array.map int

#nowarn "0025"
let [| n; y |] = readIntArray

seq {
    for i in 0..n do
        for j in 0 .. (n - i) do
            let k = n - (i + j)

            if 10000 * i + 5000 * j + 1000 * k = y then
                (i, j, k)
}
|> Seq.tryHead
|> Option.defaultValue (-1, -1, -1)
|||> printfn "%d %d %d"
