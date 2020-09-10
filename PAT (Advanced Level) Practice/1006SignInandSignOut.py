def makeTime(s):
    return tuple( [int(u) for u in s.split(':')])


def inputPerson():
    idn, sin, sout = input().split(' ')
    sin, sout = makeTime(sin), makeTime(sout)
    return (idn, sin, sout)


M = int(input())
person = inputPerson()
first, last = person, person
for i in range(1, M):
    person = inputPerson()
    if person[1] < first[1]:
        first = person
    if person[2] > last[2]:
        last = person
print(first[0], last[0])
