from queue import PriorityQueue

def inputs():
    return [int(s) for s in input().split(' ')]


def dijkstra(graph, rescues, s, d):
    lenG = len(graph)

    pathCount = [0] * lenG
    rescueCount = [0] * lenG
    dist = [0x4fffffff] * lenG
    visited = [False] * lenG

    q = PriorityQueue(lenG ** 2)

    pathCount[s] = 1
    rescueCount[s] = rescues[s]
    dist[s] = 0
    q.put((0, s))
    while not q.empty():
        _, city = q.get()
        if not visited[city]:
            visited[s] = True
            if city == d:
                return pathCount[d], rescueCount[d]
            for tocity, distance in graph[city].items():
                if dist[city] + distance < dist[tocity]:
                    pathCount[tocity] = pathCount[city]
                    rescueCount[tocity] = rescueCount[city] + rescues[tocity]
                    dist[tocity] = dist[city] + distance
                    q.put((dist[tocity], tocity))
                elif dist[city] + distance == dist[tocity]:
                    if rescueCount[city] + rescues[tocity] > rescueCount[tocity]:
                        rescueCount[tocity] = rescueCount[city] + rescues[tocity]
                    pathCount[tocity] += pathCount[city]

                


# =========================main=========================
N, M, C1, C2 = inputs()
numberOfRrescues = inputs()
assert len(numberOfRrescues) == N
graph = [{} for i in range(N)]
for i in range(M):
    c1, c2, L = inputs()
    graph[c1][c2] = L
    graph[c2][c1] = L
print(*dijkstra(graph, numberOfRrescues, C1, C2))

