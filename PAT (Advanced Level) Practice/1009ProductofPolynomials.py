from collections import defaultdict


def getPoly():
    pstring = input().split(' ')
    pstring.pop(0)
    return {int(term[0]): float(term[1]) for term in zip(pstring[0::2], pstring[1::2])}


A = getPoly()
B = getPoly()
C = defaultdict(lambda: 0.0)
for Na, coeffa in A.items():
    for Nb, coeffb in B.items():
        C[Na + Nb] += coeffa * coeffb
Clist = [(f'{N}', f'{coeff:.1f}') for N, coeff in C.items() if coeff != 0]
Clist.sort(reverse=True)
flattened = [s for term in Clist for s in term]
print(len(Clist), *flattened)
