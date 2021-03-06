(* Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms. *)

let isEven (n: uint) : bool =
    n % 2u = 0u

let rec fibonacciNumberGenerator (a : uint) (b: uint) (n: uint) : List<uint> =
    if (a + b) < n then
        (a + b) :: fibonacciNumberGenerator b (a + b) n
    else
        List.Empty

let fibonacciNumberList (n: uint) : List<uint> =
    fibonacciNumberGenerator 0u 1u n

let calculateSumOfEvenFibonacci (n: uint) : uint =
    fibonacciNumberList n
    |> List.filter isEven
    |> List.sum

printf "Enter N: "

let input = System.UInt32.Parse(System.Console.ReadLine())

let timer = System.Diagnostics.Stopwatch.StartNew()

let result = calculateSumOfEvenFibonacci input

timer.Stop()

printfn "Fibonacci list till %d is %A" input result
printfn "Time elapsed in milliseconds %f" timer.Elapsed.TotalMilliseconds

// The answer is 4613732
// Time needed 3.813500 milliseconds
