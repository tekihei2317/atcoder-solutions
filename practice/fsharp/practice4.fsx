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
