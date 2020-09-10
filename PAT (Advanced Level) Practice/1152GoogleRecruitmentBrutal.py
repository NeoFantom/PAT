import time as t
import math as m


def checkPrime(n):
    if n in {0, 1}:
        return False
    root = int(m.sqrt(n))
    for i in range(2, root + 1):
        if n % i == 0:
            return False
    return True


# ==================main==================
def main():
    L, K = [int(s) for s in input().split(' ')]
    Ns = input()
    assert len(Ns) == L

    for start in range(0, L - K + 1):
        ss = Ns[start: start + K]
        if checkPrime(int(ss)):
            print(ss)
            return
    print(404)


main()
