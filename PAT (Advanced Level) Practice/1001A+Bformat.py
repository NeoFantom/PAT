# ================Solution 1================
# ab = input().split(' ')
# a, b = [int(s) for s in ab]
# c = a + b
# li = list(str(c))
# li.reverse()
# outli = []

# i = 0
# while i + 2 < len(li):
#     outli += li[i:i+3]
#     i += 3
#     outli.append(',')
# while i < len(li):
#     outli += li[i]
#     i += 1

# if outli[-1] == ',':
#     outli = outli[0:-1]
# elif outli[-1] == '-' and outli[-2] == ',':
#     outli = outli[0:-2] + ['-']

# outli.reverse()
# s = ''
# for c in outli:
#     s += c
# print(s)

# ================Solution 2================
# ab = input().split(' ')
# a, b = [int(s) for s in ab]
# c = a + b
# s = str(abs(c))
# outs = s[-3:]

# i = len(s) - 3
# while i - 3 >= 0:
#     outs = s[i - 3: i] + ',' + outs
#     i -= 3

# i -= 1
# if i >= 0:
#     outs = ',' + outs
#     while i >= 0:
#         outs = s[i] + outs
#         i -= 1

# if c < 0:
#     outs = '-' + outs

# print(outs)

# ================Solution 2================
a, b = [int(s) for s in input().split(' ')]
print(f'{a + b:,d}', end='')

# print(f'{sum([int(s) for s in input().split(" ")]):,d}', end='')