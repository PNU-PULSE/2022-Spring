dx1 = [1, -1, 0, 0]
dy1 = [0, 0, 1, -1]

dx2 = [1, 1, -1, -1]
dy2 = [1, -1, 1, -1]

dx3 = [2, -2, 0, 0]
dy3 = [0, 0, 2, -2]


def func(place):
    for i in range(5):
        for j in range(5):
            if place[i][j] == 'P':
                # 붙어있는 경우
                for k in range(4):
                    x = i + dx1[k]
                    y = j + dy1[k]
                    if 0 <= x < 5 and 0 <= y < 5:
                        if place[x][y] == 'P':
                            return 0
                # 대각선의 경우
                for k in range(4):
                    x = i + dx2[k]
                    y = j + dy2[k]
                    if 0 <= x < 5 and 0 <= y < 5:
                        if place[x][y] == 'P':
                            if place[x][j] != 'X' or place[i][y] != 'X':
                                return 0
                # 2칸씩 떨여져 있는 경우
                for k in range(4):
                    x = i + dx3[k]
                    y = j + dy3[k]
                    if 0 <= x < 5 and 0 <= y < 5:
                        if place[x][y] == 'P':
                            if x == i:
                                if place[i][(y+j)//2] != 'X':
                                    return 0
                            else:
                                if place[(x+i)//2][j] != 'X':
                                    return 0
    return 1


def solution(places):
    answer = []
    for place in places:
        answer.append(func(place))
    return answer
