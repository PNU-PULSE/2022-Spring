def solution(n, k, cmd):
    matrix = [True] * n
    stack = []
    for c in cmd:
        if c[0] == 'U':
            c_idx = int(c[2:])
            k -= c_idx
        elif c[0] == 'D':
            c_idx = int(c[2:])
            k += c_idx
        elif c[0] == 'C':
            if k == len(matrix)-1:  # 마지막 행을 지울때
                matrix[k] = False
                stack.append([k, matrix[k]])
                del matrix[k]
                k -= 1
            else:
                matrix[k] = False
                stack.append([k, matrix[k]])
                del matrix[k]
        elif c[0] == 'Z':
            idx, flag = stack.pop()
            matrix.insert(idx, True)

    while stack:
        idx, flag = stack.pop()
        matrix.insert(idx, False)

    answer = ''
    for i in range(n):
        if matrix[i] == True:
            answer += 'O'
        else:
            answer += 'X'

    return answer
