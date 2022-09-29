module BasicFunctions =
    let sampleFunction1 x = x * x + 3
    let result1 = sampleFunction1 4573

    printfn $"4573の2乗プラス3は%d{result1}です"

module Immutability =
    let number = 2
    let mutable otherNumber = 2

    printfn $"number is {number}"
    printfn $"otherNumber is {otherNumber}"

    otherNumber <- otherNumber + 10
    printfn $"otherNumber is {otherNumber}"

module IntegersAndNumbers =
    let sampleNumbers = [ 0..99 ]
    let sampleTableOfSquares = [ for i in 0..99 -> (i, i * i) ]

    printfn $"sampleNumbers is {sampleNumbers}"
    printfn $"sampleTableOfSquares is {sampleTableOfSquares}"

module Booleans =
    let boolean1 = true
    let boolean2 = not boolean1
    let boolean3 = not boolean1 && (boolean2 || false)

    printfn $"boolean3 is {boolean3}"


module StringManipulation =
    let string1 = "Hello"
    let string2 = "World"
    let helloWorld = string1 + " " + string2

    printfn "%s" helloWorld
    printfn "%s" helloWorld[0..6]

module Tuples =
    let tuple1 = (1, 2, 3)
    let swapElems (a, b) = (b, a)

    printfn $"tuple1 is {tuple1}"
    printfn $"The result of swapping (1, 3) is {swapElems (1, 3)}"

module PipelineAndComposition =
    let numbers = [ 1; 2; 3; 4; 5 ]

    let isOdd x = x % 2 <> 0
    let square x = x * x
    let addOne x = x + 1

    let squareOddValueAndAddOne values =
        values |> List.filter isOdd |> List.map square |> List.map (fun x -> x + 1)

    printfn $"processing {numbers} through squareOddValueAndAddOne is {squareOddValueAndAddOne numbers}"

    let squareOddValueAndAddOneShorterPipeline values =
        values |> List.filter isOdd |> List.map (fun x -> x |> square |> addOne)

    printfn
        $"processing {numbers} through squareOddValueAndAddOneShorterPipeline is {squareOddValueAndAddOneShorterPipeline numbers}"

module Lists =
    let dayList =
        [ for month in 1..12 do
              for day in 1 .. System.DateTime.DaysInMonth(2022, month) do
                  yield System.DateTime(2022, month, day) ]

    printfn $"The first 5 days of 2022 are: {dayList |> List.take 5}"

    let maxNumber = 10
    let numberList = [ 1..maxNumber ]

    let sumOfSqaures =
        numberList |> List.filter (fun x -> x % 3 = 0) |> List.sumBy (fun x -> x * x)

    printfn $"1から{maxNumber}までの3の倍数の2乗の合計は、{sumOfSqaures}です"

module Array =
    let array = [| "hello"; "world"; "and"; "hello"; "world"; "again" |]

    let sumOfLengthsOfWords =
        array
        |> Array.filter (fun x -> x.StartsWith "h")
        |> Array.sumBy (fun x -> x.Length)

    printfn $"hから始まる文字列の長さの合計は、{sumOfLengthsOfWords}です"

module RecordTypes =
    type ContactCard =
        { Name: string
          Phone: string
          Verified: bool }

    let contact1 =
        { Name = "Alf"
          Phone = "(206) 555-0157"
          Verified = false }

    let contact2 =
        { contact1 with
            Phone = "(206) 555-0112"
            Verified = true }

    let showContactCard (c: ContactCard) =
        $"{c.Name} {c.Phone}" + (if not c.Verified then " (unverified)" else "")

    printfn $"contact card 1 is {showContactCard (contact1)}"
    printfn $"contact card 2 is {showContactCard (contact2)}"

module DiscriminatedUnions =
    type Suit =
        | Hearts
        | Clubs
        | Diamonds
        | Spades

    type Rank =
        | Ace
        // Represents the rank of cards 2 .. 10
        | Value of int
        | Jack
        | Queen
        | King

    type Card = { Suit: Suit; Rank: Rank }

    let allRanks =
        [ yield Ace
          for i in 2..10 do
              yield Value i
          yield Jack
          yield Queen
          yield King ]

    printfn $"All ranks are: {allRanks}"

    let fullDeck =
        [ for suit in [ Hearts; Diamonds; Clubs; Spades ] do
              for rank in allRanks do
                  yield { Suit = suit; Rank = rank } ]

    let showPlayingCard (c: Card) =
        let rankString =
            match c.Rank with
            | Ace -> "Ace"
            | Jack -> "Jack"
            | Queen -> "Queen"
            | King -> "King"
            | Value n -> string n

        let suitString =
            match c.Suit with
            | Clubs -> "clubs"
            | Diamonds -> "diamonds"
            | Spades -> "spades"
            | Hearts -> "hearts"

        $"{rankString} of {suitString}"

    let printAllCards () =
        for card in fullDeck do
            printfn $"{showPlayingCard card}"

    printAllCards ()

module SingleCaseDiscriminatedUnion =
    type Address = Address of string
    let unwrapAddress (Address a) = a

    let unwrapAddress2 a =
        match a with
        | Address a -> a

    let address = Address "111 Alf Way"
    printfn $"{address}"
    printfn $"{address |> unwrapAddress}"
    printfn $"{address |> unwrapAddress2}"
