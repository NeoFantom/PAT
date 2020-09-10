'''
type 1: level -> testees by descending score
type 2: site -> num of testees AND total score
type 3: date -> num of testees for each site
'''


def parseCard(s, score):
    return {'card': s, 'level': s[0], 'site': s[1:4], 'date': s[4:10], 'testee': s[10:], 'score': int(score)}


# ==========================main==========================
N, M = [int(s) for s in input().split(' ')]
students = []
levels = {'T': [], 'A': [], 'B': []}
sites = {}
dates = {}
datesAns = {}
queries = []
for i in range(N):
    students.append(parseCard(*input().split(' ')))
for i in range(M):
    ty, term = input().split(' ')
    queries.append((int(ty), term))

for stu in students:
    levels[stu['level']].append((stu['card'], stu['score']))
    site = stu['site']
    if site in sites:
        sites[site][0] += 1
        sites[site][1] += stu['score']
    else:
        sites[site] = [1, stu['score']]
    date = stu['date']
    if date in dates:
        site2count = dates[date]
        site2count[site] = site2count.get(site, 0) + 1
    else:
        dates[date] = {stu['site']: 1}

for li in levels.values():
    li.sort(key=lambda card_score: (105 - card_score[1], card_score[0]))
for date, di in dates.items():
    li = [(site, count) for site, count in di.items()]
    li.sort(key=lambda site_count: (100000 - site_count[1], site_count[0]))
    datesAns[date] = li

count = 1
for q in queries:
    print(f'Case {count}: {q[0]} {q[1]}')
    count += 1
    if q[0] == 1:
        ans = levels[q[1]]
        if len(ans) > 0:
            for card_score in ans:
                print(*card_score)
        else:
            print('NA')
    if q[0] == 2:
        if q[1] in sites:
            print(*sites[q[1]])
        else:
            print('NA')
    if q[0] == 3:
        if q[1] in datesAns:
            for site_count in datesAns[q[1]]:
                print(*site_count)
        else:
            print('NA')
