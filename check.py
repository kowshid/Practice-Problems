def countPairs():
    p = 1
    powers = [int] * 41
    for i in range(41):
        powers[i] = p
        p *= 2

    print(powers)

countPairs()