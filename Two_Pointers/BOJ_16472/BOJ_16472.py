import sys
alphabet = [0 for _ in range(26)]
a = int(sys.stdin.readline())
string = [0] + list(sys.stdin.readline().rstrip("\n"))
n = len(string) - 1
l, r = 1, 1
cnt = mx = 0
while r <= n:
    if alphabet[ord(string[r]) - 97] == 0:  cnt += 1
    alphabet[ord(string[r]) - 97] += 1
    if cnt > a:
        while True:
            p = ord(string[l]) - 97
            l += 1
            alphabet[p] -= 1
            if alphabet[p] == 0:  break
        cnt -= 1
    mx = max(mx, r - l + 1)
    r += 1
print(mx)