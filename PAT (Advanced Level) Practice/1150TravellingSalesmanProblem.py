def inputs():
    return [int(s) for s in input().split(' ')]


N, M = inputs()
dist = [[None] * (N+1) for i in range(N+1)]
for city in range(M):
    c1, c2, d = inputs()
    dist[c1][c2] = d
    dist[c2][c1] = d
K = inputs()[0]
best = (0, 0x7fffffff)
for i in range(K):
    line = inputs()
    n = line[0]
    path = line[1:]

    totalDist = 0
    isTS = path[0] == path[-1]
    isSimple = True

    visited = [False] * (N+1)
    visited[path[0]] = True
    for city in range(1, n):
        fr, to = path[city - 1], path[city]

        if dist[fr][to] is None:
            isTS = False
            totalDist = 'NA'
            break
        else:
            totalDist += dist[fr][to]
            if visited[to] and to != path[-1]:
                isSimple = False
            visited[to] = True
    visited[0] = True
    if False in visited:
        isTS = False
    
    if isTS and totalDist < best[1]:
        best = (i + 1, totalDist)

    if not isTS:
        print(f'Path {i + 1}: {totalDist} (Not a TS cycle)')
    elif not isSimple:
        print(f'Path {i + 1}: {totalDist} (TS cycle)')
    else:
        print(f'Path {i + 1}: {totalDist} (TS simple cycle)')

print(f'Shortest Dist({best[0]}) = {best[1]}')
