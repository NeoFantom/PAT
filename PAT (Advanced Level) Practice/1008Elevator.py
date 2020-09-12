numbers = [int(s) for s in input().split(' ')]
N = numbers[0]
numbers[0] = 0
totalTime = 0
for i in range(1, len(numbers)):
    diff = numbers[i] - numbers[i - 1]
    travel = diff * 6 if diff > 0 else abs(diff) * 4
    totalTime += travel + 5
print(totalTime)