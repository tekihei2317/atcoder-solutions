module ComputationExpressionLog =
    let log p = printfn "expression is %A" p

    let loggedWorkflow =
        let x = 42
        log x
        let y = 43
        log y
        let z = x + y
        log z
        z

    type LoggingBuilder() =
        let log p = printfn "expression is %A" p

        member this.Bind(x, f) =
            log x
            f x

        member this.Return(x) = x

    let logger = new LoggingBuilder()

    let loggedWorkflow2 =
        logger {
            let! x = 42
            let! y = 43
            let! z = x + y
            return z
        }

module ComputationExpressionDivision =
    let divideBy bottom top =
        if bottom = 0 then None else Some(top / bottom)

    let divideByWorkflow init x y z =
        let result1 = init |> divideBy x

        let result2 =
            match result1 with
            | None -> None
            | Some (a) -> a |> divideBy y

        let result3 =
            match result2 with
            | None -> None
            | Some (a) -> a |> divideBy z

        result3

    printfn "good: %A" (divideByWorkflow 12 3 2 1)
    printfn "bad: %A" (divideByWorkflow 12 3 0 1)

    type MaybeBuilder() =
        member this.Bind(x, f) =
            match x with
            | None -> None
            | Some a -> f a

        member this.Return(x) = Some x

    let maybe = new MaybeBuilder()

    let divideByWorkflow2 init x y z =
        maybe {
            let! a = init |> divideBy x
            let! b = a |> divideBy y
            let! c = b |> divideBy z
            return c
        }

    printfn "good: %A" (divideByWorkflow2 12 3 2 1)
    printfn "bad: %A" (divideByWorkflow2 12 3 0 1)

module ContinuationExample =
    let divide ifZero ifSuccess a b =
        if b = 0 then ifZero () else ifSuccess (a / b)

    let divideAndPrint =
        let ifZero () = printfn "bad"
        let ifSuccess x = printfn "good %d" x
        divide ifZero ifSuccess

    let divideAndConvertToOption =
        let ifZero () = None
        let ifSuccess x = Some(x)
        divide ifZero ifSuccess

    let divideAndThrowException =
        let ifZero () = failwith "divide by 0"
        let ifSuccess x = x
        divide ifZero ifSuccess

    divideAndPrint 6 3
    divideAndPrint 6 0
    divideAndConvertToOption 6 3
    divideAndConvertToOption 6 0
    divideAndThrowException 6 3
// divideAndThrowException 6 0

module BindExample =
    // これは
    // let! x = 10
    // printfn "%d" x

    // これと同じ
    // Bind(10, (fun x -> printfn "%d", x))

    let (<<=) m f =
        printfn "expression is %A" m
        f m

    let loggingWorkflow = 1 <<= (+) 2 <<= (*) 42 <<= id

module DivideByWithBindFunction =
    let divideBy bottom top =
        if bottom = 0 then None else Some(top / bottom)

    let bind m f = Option.bind f m
    let return' x = Some x

    let divideByWorkflow x y z w =
        bind (x |> divideBy y) (fun a -> bind (a |> divideBy w) (fun b -> return' b))

    let good = divideByWorkflow 12 3 2 1
    printfn "good: %A" good

module DivideByWithComputationExpression =
    let divideBy bottom top =
        if bottom = 0 then None else Some(top / bottom)

    type MaybeBuilder() =
        member this.Bind(m, f) = Option.bind f m
        member this.Return(x) = Some(x)

    let maybe = new MaybeBuilder()

    let divideByWorkflow x y z w =
        maybe {
            let! a = x |> divideBy y
            let! b = a |> divideBy z
            let! c = b |> divideBy w
            return c
        }

    let good = divideByWorkflow 12 3 2 1
    printfn "good: %A" good

module StringAddWorkflow =
    let strToInt x =
        try
            Some(x |> int)
        with :? System.FormatException ->
            None

    printfn "good: %A" ("123" |> strToInt)
    printfn "bad: %A" ("aaa" |> strToInt)

    type MaybeBuilder() =
        member this.Bind(m, f) = Option.bind f m
        member this.Return(x) = Some(x)

    let maybe = new MaybeBuilder()

    let stringAddWorkflow x y z =
        maybe {
            let! a = strToInt x
            let! b = strToInt y
            let! c = strToInt z
            return a + b + c
        }

    let stringAddWorkflow2 x y z =
        let a = x |> strToInt
        let b = y |> strToInt
        let c = z |> strToInt

        match a with
        | None -> None
        | Some (x) ->
            match b with
            | None -> None
            | Some (y) ->
                match c with
                | None -> None
                | Some (z) -> Some(x + y + z)

    stringAddWorkflow "12" "3" "2" |> printfn "good: %A"
    stringAddWorkflow "12" "xyz" "2" |> printfn "bad: %A"
    stringAddWorkflow2 "12" "3" "2" |> printfn "good: %A"
    stringAddWorkflow2 "12" "xyz" "2" |> printfn "bad: %A"
