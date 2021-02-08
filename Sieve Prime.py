import math
def sieve(n):
    prime = [True] * n

    for i in range(2, int(math.sqrt(n))+1):
        j = 2
        if prime[i]:
            while(i*j < n):
                prime[i*j] = False
                j += 1

    for i in range(2, n):
        if prime[i]:
            print(i)

sieve(100000)