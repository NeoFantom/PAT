K = int(input())
li = [int(s) for s in input().split(' ')]

if all([n < 0 for n in li]):
    print(0, li[0], li[-1])
else:
    sum_i_j_start_end = [(li[i], -i, -i, li[i], li[i]) for i in range(len(li))]
    for i in range(1, len(li)):
        newsum = sum_i_j_start_end[i - 1][0] + li[i]
        if newsum > li[i]:
            sum_i_j_start_end[i] = (newsum, sum_i_j_start_end[i-1][1], -i,
                                    sum_i_j_start_end[i-1][3], li[i])
    maxsum = max(sum_i_j_start_end)
    print(maxsum[0], maxsum[3], maxsum[4])
