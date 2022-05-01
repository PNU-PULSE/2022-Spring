import sys
from collections import deque
n, m = map(int, sys.stdin.readline().split())
mpg = [[0 for _ in range(m + 1)]] + [[0] + list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visit = [[0] + [[False, False, False, False] for _ in range(m + 1)] for _ in range(n + 1)]
cnt = 0
def posfind(i, j, direct):
    if direct == 0:
        return i, j - 1, direct
    elif direct == 1:
        return i, j + 1, direct
    elif direct == 2:
        return i - 1, j, direct
    else:
        return i + 1, j, direct
def directchange3(direct):
    if direct == 0:
        return 3
    elif direct == 3:
        return 0
    elif direct == 2:
        return 1
    return 2
def directchange4(direct):
    if direct == 0:
        return 2
    elif direct == 2:
        return 0
    elif direct == 1:
        return 3
    return 1
def dfs(i, j):
    global cnt
    stack = deque()
    if not visit[i][j][1]:
        stack.appendleft([i, j - 1, 0])
    if not visit[i][j][0]:
        stack.appendleft([i, j + 1, 1])
    if not visit[i][j][3]:
        stack.appendleft([i - 1, j, 2])
    if not visit[i][j][2]:
        stack.appendleft([i + 1, j, 3])
    visit[i][j] = [True, True, True, True]#방향 0: left, 1: right, 2: up, 3: down
    while stack:
        posx, posy, direct = stack.popleft()
        if posx <= 0 or posy <= 0 or posx >= n + 1 or posy >= m + 1:
            continue  
        if not (visit[posx][posy][0]) and (not visit[posx][posy][1]) and (not visit[posx][posy][2]) and (not visit[posx][posy][3]):
            if mpg[posx][posy] != 9:
                cnt += 1
        visit[posx][posy][direct] = True
        if mpg[posx][posy] == 9:
            continue
        elif mpg[posx][posy] == 0:
            posx, posy, direct = posfind(posx, posy, direct)
            stack.appendleft([posx, posy, direct])
        elif mpg[posx][posy] == 1:
            if direct == 0 or direct == 1:
                continue
            posx, posy, direct = posfind(posx, posy, direct)
            stack.appendleft([posx, posy, direct])
        elif mpg[posx][posy] == 2:
            if direct == 2 or direct == 3:
                continue
            posx, posy, direct = posfind(posx, posy, direct)
            stack.appendleft([posx, posy, direct])
        elif mpg[posx][posy] == 3:
            direct = directchange3(direct)
            visit[posx][posy][direct] = True
            posx, posy, direct = posfind(posx, posy, direct)
            stack.appendleft([posx, posy, direct])
        elif mpg[posx][posy] == 4:
            direct = directchange4(direct)
            visit[posx][posy][direct] = True
            posx, posy, direct = posfind(posx, posy, direct)
            stack.appendleft([posx, posy, direct])
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if mpg[i][j] == 9:
            cnt += 1
            dfs(i, j)
print(cnt)