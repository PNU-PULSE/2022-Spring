import sys
al = [[0] for _ in range(26)]
s = [0] + list(sys.stdin.readline().rstrip("\n"))
t = [0] + list(sys.stdin.readline().rstrip("\n"))
a, b = len(s) - 1, len(t) - 1
p, cnt = 0, 1
for i in range(1, b + 1):
    f = ord(t[i]) - 97
    al[f].append(i)
    al[f][0] += 1
for i in range(1, a + 1):
    f = ord(s[i]) - 97
    if al[f][0] == 0:
        cnt = -1
        break
    if p >= al[f][-1]:
        cnt += 1
        p = al[f][1]
        continue
    l, r = 1, al[f][0]
    while l <= r:
        m = (l + r) // 2
        if al[f][m] > p:  r = m - 1
        else:  l = m + 1
    p = al[f][l]
print(cnt)