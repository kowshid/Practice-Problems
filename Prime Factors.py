import math

prime = None

def sieve(n):
    global prime
    prime = [True] * (n+1)
    for i in range(2, int(math.sqrt(n))+1):
        j = 2
        if prime[i]:
            while(i*j <= n):
                prime[i*j] = False
                j += 1

def primeFactors(n):
    factors = []
    sieve(n)
    itr = 2
    while itr <= n:
        if prime[itr]:
            if n % itr == 0:
               factors.append(itr)
        itr += 1
    return factors

print(primeFactors(17))