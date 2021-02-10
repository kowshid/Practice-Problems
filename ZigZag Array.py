def zigzagArray(arr):
    n = len(arr)
    flag = True
    for i in range(n-1):
        if flag:
            if arr[i] > arr[i+1]:
                arr[i] = arr[i] ^ arr[i + 1]
                arr[i + 1] = arr[i] ^ arr[i + 1]
                arr[i] = arr[i] ^ arr[i + 1]

        else:
            if arr[i] < arr[i + 1]:
                arr[i] = arr[i] ^ arr[i + 1]
                arr[i + 1] = arr[i] ^ arr[i + 1]
                arr[i] = arr[i] ^ arr[i + 1]

        flag = not flag

    return arr

arr = [4, 3, 7, 8, 6, 2, 1]
print(zigzagArray(arr))