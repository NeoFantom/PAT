Ns, Ks = input().split(" ")
Rs = Ns[::-1]
K = int(Ks)
count = 0

while Ns != Rs and count < K:
    N, R = int(Ns), int(Rs)
    Ns = str(N + R)
    Rs = Ns[::-1]
    count += 1

print(Ns)
print(count)