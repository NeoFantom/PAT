from queue import PriorityQueue, Queue

def inputs():
    return [int(s) for s in input().split(' ')]


N, M, S, D = inputs()
edgesFrom = [[] for i in range(N)]
for _ in range(M):
    fr, to, dist, cost = inputs()
    edgesFrom[fr].append((to, dist, cost))
    edgesFrom[to].append((fr, dist, cost))


# spfa
dist = [0x4fffffff] * N
cost = [0x4fffffff] * N
pre = [-1] * N
dist[S] = 0
cost[S] = 0

q = Queue(N)
inQ = [False] * N
q.put(S)
inQ[S] = True
while not q.empty():
    fr = q.get()
    inQ[fr] = False
    for to, d, c in edgesFrom[fr]:
        newdist = dist[fr] + d
        newcost = cost[fr] + c
        if newdist < dist[to]:
            dist[to] = newdist
            cost[to] = newcost
            pre[to] = fr
            if not inQ[to]:
                q.put(to)
                inQ[to] = True
        elif dist[to] == newdist and newcost < cost[to]:
            dist[to] = newdist
            cost[to] = newcost
            pre[to] = fr
            if not inQ[to]:
                q.put(to)
                inQ[to] = True

# dijkstra
dist = [0x4fffffff] * N
cost = [0x4fffffff] * N
pre = [-1] * N
dist[S] = 0
cost[S] = 0

q = PriorityQueue(N)
visited = [False] * N
q.put((0, 0, S))
while not q.empty():
    fr = q.get()[2]
    if not visited[fr]:
        visited[fr] = True
        for to, d, c in edgesFrom[fr]:
            if not visited[to]:
                newdist = dist[fr] + d
                newcost = cost[fr] + c
                if newdist < dist[to]:
                    dist[to] = newdist
                    cost[to] = newcost
                    pre[to] = fr
                    q.put((newdist, newcost, to))
                elif dist[to] == newdist and newcost < cost[to]:
                    dist[to] = newdist
                    cost[to] = newcost
                    pre[to] = fr
                    q.put((newdist, newcost, to))

v = D
ans = [D]
while pre[v] != -1:
    v = pre[v]
    ans.append(v)
print(*list(reversed(ans)), dist[D], cost[D])