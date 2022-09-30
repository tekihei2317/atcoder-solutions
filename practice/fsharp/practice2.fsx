module Sum =
    let sumOfSquares n = [ 1..n ] |> List.sumBy (fun i -> i * i)

    printfn "1から10までの2乗の合計は%dです" (sumOfSquares 10)

module Sort =
    let rec quicksort list =
        match list with
        | [] -> []
        | firstElem :: otherElements ->
            let smallerElements =
                otherElements |> List.filter (fun e -> e < firstElem) |> quicksort

            let largerElements =
                otherElements |> List.filter (fun e -> e >= firstElem) |> quicksort

            List.concat [ smallerElements; [ firstElem ]; largerElements ]

    printfn "%A" (quicksort [ 1; 5; 23; 18; 9; 1; 3 ])

    let rec quicksort2 list =
        match list with
        | [] -> []
        | first :: rest ->
            let smaller, larger = List.partition ((>=) first) rest
            List.concat [ quicksort smaller; [ first ]; quicksort larger ]

    printfn "%A" (quicksort2 [ 1; 5; 23; 18; 9; 1; 3 ])

// open System.Net
// open System

// module WebPageDownload =
// let fetchUrl callback url =
//     let req = WebRequest.Create(Uri(url))
//     use res = req.GetResponse()
//     use stream = res.GetResponseStream()
//     use reader = new IO.StreamReader(stream)
//     callback reader url

// let myCallback (reader: IO.StreamReader) url =
//     let html = reader.ReadToEnd()
//     let html1000 = html.Substring(0, 1000)
//     printfn "Downloaded %s. First 100 is %s\n" url html1000

// let fetchUrlAndPrint = fetchUrl myCallback
// fetchUrlAndPrint "https://www.google.com"
// fetchUrlAndPrint "https://www.yahoo.co.jp/"

module Accumulation =
    // 1からnまでの積
    let product n =
        [ 1..n ] |> List.fold (fun sum i -> i * sum) 1

    printfn "1から10までの積は%dです" (product 10)
    // 1からnまでの奇数の合計
    let oddSum n =
        [ 1..n ] |> List.filter (fun i -> i % 2 = 1) |> List.sum

    let oddSum2 n =
        let action sum x = sum + (if x % 2 = 1 then x else 0)
        [ 1..n ] |> List.fold action 0

    printfn "1から10までの奇数の合計は%dです" (oddSum 10)
    printfn "1から10までの奇数の合計は%dです" (oddSum2 10)

    // 1からnまでのを交互に足す
    let alternatingSum n =
        [ 1..n ]
        |> List.mapi (fun index value -> value * (if index % 2 = 0 then 1 else -1))
        |> List.sum

    printfn "1から10までを交互の足し引きすると%dになります" (alternatingSum 10)

    let sumOfSquares n =
        let action sum x = sum + x * x
        [ 1..n ] |> List.fold action 0

    printfn "1から10までの2乗和は%dです" (sumOfSquares 10)

    // maxBy
    type NameAndSize = { Name: string; Size: int }

    let list =
        [ { Name = "Alice"; Size = 10 }
          { Name = "Bob"; Size = 1 }
          { Name = "Carol"; Size = 12 }
          { Name = "David"; Size = 5 } ]

    let maxNameAndSize list =
        match list with
        | [] -> None
        | _ ->
            let max = list |> List.maxBy (fun item -> item.Size)
            Some max

    printfn $"{maxNameAndSize list}"
    printfn $"{maxNameAndSize []}"
