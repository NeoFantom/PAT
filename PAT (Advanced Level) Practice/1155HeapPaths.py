N = int(input())
li = [int(s) for s in input().split(' ')]
assert N == len(li)
li.append(li[0])


def dfs(i):
    if i < N:
        path.append(li[i])
        dfs(i * 2 + 2)
        dfs(i * 2 + 1)
        path.pop()
    elif i % 2 == 1:
        print(*path)


isMax = True
isMin = True
for i in range(1, N):
    if li[(i - 1) // 2] < li[i]:
        isMax = False
    if li[(i - 1) // 2] > li[i]:
        isMin = False
path = []
dfs(0)
print('Max Heap' if isMax else 'Min Heap' if isMin else 'Not Heap')
