def intToString(n):
    temp = n
    strarr = []
    while(temp):
        char = chr(temp % 10 + ord('0'))
        strarr.append(char)
        temp = temp // 10

    strarr.reverse()

    return "".join(strarr)

print(intToString(41413))