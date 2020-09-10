import math as m

isPrime = []
primes = []


def makePrimeTableUnder(n):
    global isPrime
    global primes
    isPrime = [True] * n
    isPrime[0] = False
    isPrime[1] = False

    root = m.sqrt(n)
    i = 2
    while i <= root:
        if isPrime[i]:
            primes.append(i)
            for k in range(i * 2, n, i):
                isPrime[k] = False
        i += 1
    while i < n:
        if isPrime[i]:
            primes.append(i)
        i += 1


def checkPrime(n):
    if n < len(isPrime):
        return isPrime[n]
    else:
        root = m.sqrt(n)
        for p in primes:
            if p > root:
                break
            if n % p == 0:
                return False
        return True


# ==================main==================
L, K = [int(s) for s in input().split(' ')]
Ns = input()
assert len(Ns) == L

makePrimeTableUnder(100000)
hasPrime = False
for start in range(0, L - K + 1):
    ss = Ns[start: start + K]
    if checkPrime(int(ss)):
        print(ss)
        hasPrime = True
        break
if not hasPrime:
    print(404)
