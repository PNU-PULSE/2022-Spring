import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()

left, right = 0, N-1
answer = float('INF')
ans_left, ans_right = 0, 0

while left < right:

    sub = abs(arr[left] + arr[right])

    if sub < answer:
        answer = sub
        ans_left = arr[left]
        ans_right = arr[right]

    if abs(arr[left+1] + arr[right]) < abs(arr[left] + arr[right-1]):
        left += 1
    else:
        right -= 1

print(ans_left, ans_right)
