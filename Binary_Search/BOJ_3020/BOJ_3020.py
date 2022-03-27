import sys
input = sys.stdin.readline

N, H = map(int, input().split())
up, down = [], []
for i in range(N):
    if i%2:
        up.append(int(input()))
    else:
        down.append(int(input()))

up.sort()
down.sort()

def binary_search(arr, target, left, right):
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return left

D, U = len(down), len(up)
count_minimum = 0
minimum = float('inf')
for i in range(1, H+1):
    count_down = D - binary_search(down, i-0.5, 0, D-1)
    count_up = U - binary_search(up, H-i+0.5, 0, U-1)

    if count_down + count_up < minimum:
        minimum = count_down + count_up
        count_minimum = 1

    elif count_down + count_up == minimum:
        count_minimum += 1

print(minimum, count_minimum)




