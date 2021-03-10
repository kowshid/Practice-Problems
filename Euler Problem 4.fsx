(*
    Project Euler #4

    Largest palindrome product
    --------------------

    A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
    Find the largest palindrome made from the product of two 3-digit numbers.
*)


let rec reverseNumber (current: uint) (accumulator: uint) : uint =
    match current with
    | 0u -> accumulator
    | _ -> reverseNumber (current / 10u) ((accumulator * 10u) + (current % 10u))

let isPalindrome (num: uint) : bool =
    num = (reverseNumber num 0u)

let getLargestPalindromeOf3DigitNumbersMultiple : uint =
    seq {
            for x in {100u .. 999u} do
                for y in {100u .. 999u} do
                    yield (x * y)
        }
    |> Seq.filter isPalindrome
    |> Seq.max

let timer = System.Diagnostics.Stopwatch.StartNew()

printfn "The largest palindrome made from the product of two 3-digit numbers %d" getLargestPalindromeOf3DigitNumbersMultiple

timer.Stop()

printfn "Time elapsed in milliseconds %f" timer.Elapsed.TotalMilliseconds
