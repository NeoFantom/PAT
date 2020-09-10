import math as m

isPrime = []
primes = []

def primeTableUnder(n):
    n = int(n)
    global isPrime
    isPrime = [True] * n
    root = m.sqrt(n)
    i = 2
    while i <= root:
        if isPrime[i]:
            primes.append(i)
            k = i + i
            for k in range(i * 2, n, i):
                isPrime[k] == False
        i += 1
    while i < n:
        if isPrime[i]:
            primes.append(i)
        i += 1


def checkPrime(n):
    root = m.sqrt(n)
    for p in primes:
        if p > root:
            break
        elif n % p == 0:
            return False
    return True


# ======================main======================
# Too slow ❌
date = input()
primeTableUnder(m.sqrt(int(date)) + 1)

allprime = True
for i in range(len(date)):
    part = date[i:]
    if checkPrime(int(part)):
        yn = 'Yes'
    else:
        yn = 'No'
        allprime = False
    print(part, yn, end='\n' if i != len(date) - 1 else '')
if allprime:
    print('\nAll Prime!')
