repeat = int(input())
s = input()
possibleKeys = dict([(c, None) for c in s]) # dict used as ordered set

lastk, count = '*', 0
for k in s + '*':
    if lastk == k:
        count += 1
    else:
        if count % repeat != 0 and lastk in possibleKeys:
            possibleKeys.pop(lastk)
        lastk, count = k, 1

print(*possibleKeys, sep='')
for k in possibleKeys:
    s = s.replace(k * repeat, k)
print(s)
