digits = [int(c) for c in input()]
out = str(sum(digits))
english = 'zero one two three four five six seven eight nine ten'.split(' ')
out = [english[int(i)] for i in out]
print(*out, end='')