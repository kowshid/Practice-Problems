(* The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ? *)

let isPrime (n: uint64) : bool =
    let halfOfN = n / 2UL
    {2UL .. halfOfN}
    |> Seq.forall (fun x -> n % x <> 0UL)

let maxPrimeFactorOfN (n: uint64) : uint64 =
    let halfOfN = n / 2UL
    {2UL .. halfOfN}
    |> Seq.filter isPrime
    |> Seq.filter (fun x -> n % x = 0UL)
    |> Seq.max

printf "Enter N: "

let input = System.UInt64.Parse(System.Console.ReadLine())

let timer = System.Diagnostics.Stopwatch.StartNew()

let result = maxPrimeFactorOfN input

timer.Stop()

printfn "Maximum Prime Factor of %d is %d" input result
printfn "Time elapsed in milliseconds %f" timer.Elapsed.TotalMilliseconds
