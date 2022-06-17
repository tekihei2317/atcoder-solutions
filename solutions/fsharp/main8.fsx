#nowarn "0025"
let [| N; Y |] = stdin.ReadLine().Split() |> Array.map int

let answers =
    [ for i = 0 to N do
          for j = 0 to N - i do
              let k = N - (i + j)

              if 10000 * i + 5000 * j + 1000 * k = Y then
                  [ i; j; k ] ]

let answer =
    if answers.Length = 0 then
        [ -1; -1; -1 ]
    else
        answers.Head

answer
|> List.map string
|> String.concat " "
|> stdout.WriteLine
