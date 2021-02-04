def isomorphic(str1, str2):
    len1 = len(str1)
    len2 = len(str2)

    if len1 != len2:
        return False

    visited = [False] * 26
    mapping = [-1] * 26

    for i in range(len1):
        if mapping[ord(str1[i]) - ord('a')] == -1:
            if visited[ord(str2[i]) - ord('a')] == True:
                return False

            mapping[ord(str1[i]) - ord('a')] = ord(str2[i]) - ord('a')
            visited[ord(str2[i]) - ord('a')] = True

        elif mapping[ord(str1[i]) - ord('a')] != ord(str2[i]) - ord('a'):
            return False
    return True

def main():
    print("ahsan", "kowshid")
    print(isomorphic("ahsan", "waqar"))
    print(isomorphic("aab", "xxy"))

if __name__ == '__main__':
    main()