def parseCard(s, score):
    # return ['card', 'level', 'site', 'date', 'testee', 'score']
    return [s,         s[0],    s[1:4], s[4:10], s[10:],   int(score)]


# ==========================main==========================
N, M = [int(s) for s in input().split(' ')]
students = []
queries = []
for i in range(N):
    students.append(parseCard(*input().split(' ')))
for i in range(M):
    ty, term = input().split(' ')
    queries.append((int(ty), term))

# students.sort(key=lambda stu: (105 - stu[5], stu[0]))

count = 1
for q in queries:
    print(f'Case {count}: {q[0]} {q[1]}')
    count += 1
    if q[0] == 1:
        ans = []
        for st in students:
            if st[1] == q[1]:
                ans.append((st[0], st[5]))
        if len(ans) == 0:
            print('NA')
        else:
            ans.sort(key=lambda card_score: (
                105 - card_score[1], card_score[0]))
            for a in ans:
                print(a[0], a[1])
    if q[0] == 2:
        Nt, Ns = 0, 0
        for st in students:
            if st[2] == q[1]:
                Nt += 1
                Ns += st[5]
        if Nt == 0:
            print('NA')
        else:
            print(Nt, Ns)
    if q[0] == 3:
        # (site, Nt)
        ans = {}
        for st in students:
            if st[3] == q[1]:
                site = int(st[2])
                ans[site] = ans.get(site, 0) + 1
        ans = [(it[0], it[1]) for it in ans.items()]
        ans.sort(key=lambda it: (100000 - it[1], it[0]))
        if len(ans) == 0:
            print('NA')
        for a in ans:
            print(a[0], a[1])
