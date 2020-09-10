

N, M = [int(s) for s in input().split(' ')]
edges = []
for i in range(M):
    edges.append([int(s) for s in input().split(' ')])
KK = int(input())
for i in range(KK):
    color = [int(s) for s in input().split(' ')]
    k = len(set(color))
    yes = True
    for e in edges:
        if color[e[0]] == color[e[1]]:
            yes = False
            break
    print(f'{k}-coloring' if yes else 'No')

