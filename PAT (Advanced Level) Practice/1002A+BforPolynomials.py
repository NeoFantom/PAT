import sys


def group(li, size):
    newli = []
    for i in range(size):
        newli.append(li[i::size])
    return list(zip(*newli))


def getPoly():
    li = input().split(' ')
    K = int(li.pop(0))
    i = 0
    p = {}
    while i < len(li):
        p[int(li[i])] = float(li[i + 1])
        i += 2
    assert K == len(p)
    return p    


a = getPoly()
b = getPoly()
for k, v in a.items():
    b[k] = b.get(k, 0) + v

ans = list(filter(lambda ra: ra[1] != 0, sorted(list(b.items()), reverse=True)))
print(len(ans), end='')
for r, a in ans:
    if a != 0:
        print(' {} {:.1f}'.format(r, a), end='')