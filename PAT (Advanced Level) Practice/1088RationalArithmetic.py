import math as m
from fractions import Fraction


def norm(r):
    k, frac = int(r), r - int(r)
    if k != 0 and frac != 0:
        s = f'{k} {abs(frac)}'
    elif frac == 0:
        s = f'{k}'
    else:
        s = f'{frac}'

    if r < 0:
        s = f'({s})'
    return s


r1, r2 = [Fraction(s) for s in input().split(' ')]
print(f'{norm(r1)} + {norm(r2)} = {norm(r1 + r2)}')
print(f'{norm(r1)} - {norm(r2)} = {norm(r1 - r2)}')
print(f'{norm(r1)} * {norm(r2)} = {norm(r1 * r2)}')
if r2 != 0:
    print(f'{norm(r1)} / {norm(r2)} = {norm(r1 / r2)}')
else:
    print(f'{norm(r1)} / {norm(r2)} = Inf')
