// Optionは、空かもしれない型を表す
module OptionExample =
    let keepIfPositive n = if n > 0 then Some(n) else None

    let extractValue (n: int option) =
        match n with
        | Some (n) -> n
        | None -> 0

    // Optionモジュールを使ってみる
    let extractValue2 (n: int option) =
        if Option.isSome n then Option.get n else 0

    // Option.defaultValue便利
    let extractValue3 (n: int option) = n |> Option.defaultValue 0

    let exists n =
        match n with
        | Some (_) -> true
        | None -> false

    // Option.existsも便利そう
    let exists2 n = Option.isSome n

    10 |> keepIfPositive |> extractValue |> printfn "%d"
    10 |> keepIfPositive |> extractValue2 |> printfn "%d"
    10 |> keepIfPositive |> extractValue3 |> printfn "%d"
    10 |> keepIfPositive |> exists |> printfn "%b"
    10 |> keepIfPositive |> exists2 |> printfn "%b"
    -7 |> keepIfPositive |> extractValue |> printfn "%d"
    -7 |> keepIfPositive |> extractValue2 |> printfn "%d"
    -7 |> keepIfPositive |> extractValue3 |> printfn "%d"
    -7 |> keepIfPositive |> exists |> printfn "%b"
    -7 |> keepIfPositive |> exists2 |> printfn "%b"

    let rec tryFindMatch pred list =
        match list with
        | head :: rest -> if pred (head) then Some(head) else tryFindMatch pred rest
        | [] -> None

    let list = [ 200; 100; 50; 25 ]
    list |> tryFindMatch (fun n -> n = 100) |> printfn "%A" // なんでも表示したいときは%Aがよさそう
    list |> tryFindMatch (fun n -> n = 26) |> printfn "%A"

// Resultは、失敗するかもしれない型を表す
module ResultExample =
    type Request = { Name: string; Email: string }

    let validateName (req: Request) =
        match req.Name with
        | null -> Error "No name found."
        | "" -> Error "Name is empty."
        | "bananas" -> Error "Bananas is not a name."
        | _ -> Ok(req)

    let validateEmail (req: Request) =
        match req.Email with
        | null -> Error "No email found."
        | "" -> Error "Email is empty."
        | s when s.EndsWith "bananas.com" -> Error "No email from bananas.com is allowd."
        | _ -> Ok(req)

    let validateRequest reqResult =
        reqResult |> Result.bind validateName |> Result.bind validateEmail

    let validateRequest2 reqResult =
        // Result.bindは、Errorの場合はErrorで通し、Okの場合は関数を実行する
        match reqResult with
        | Error e -> Error e
        | Ok x -> validateName x
        |> function
            | Error e -> Error e
            | Ok x -> validateEmail x


    let validateRequestAndPrint req =
        let res = validateRequest (Ok req)

        match res with
        | Ok req -> printfn "My request was valid! Name: %s Email %s" req.Name req.Email
        | Error e -> printfn "Error: %s" e

    let validateRequestAndPrint2 req =
        let res = validateRequest2 (Ok req)

        // Result.bindを使う
        let reqResult = Ok req
        reqResult |> Result.bind validateEmail |> ignore

        // パターンマッチ
        match reqResult with
        | Error e -> Error e
        | Ok x -> validateEmail x
        |> ignore

        // functionを使ったパターンマッチ（これどういう名前の構文なんだろう）
        reqResult
        |> function
            | Error e -> Error e
            | Ok x -> validateEmail x
        |> ignore

        match res with
        | Ok req -> printfn "My request was valid! Name: %s Email %s" req.Name req.Email
        | Error e -> printfn "Error: %s" e

    let test () =
        let req1 =
            { Name = "Phillip"
              Email = "phillip@contoso.biz" }

        let req2 =
            { Name = "Phillip"
              Email = "phillip@bananas.com" }

        validateRequestAndPrint req1
        validateRequestAndPrint2 req1
        validateRequestAndPrint req2
        validateRequestAndPrint2 req2

    test ()
