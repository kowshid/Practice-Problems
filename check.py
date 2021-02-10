from collections import defaultdict

test = defaultdict(lambda : False)

for i in range(10):
    test[i] = True

for key in test:
    if test[key]:
        print(key)