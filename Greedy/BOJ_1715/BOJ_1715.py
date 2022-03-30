import heapq
import sys
n = int(input())
cards = list()
answer = 0
for _ in range(n):
    heapq.heappush(cards,int(sys.stdin.readline()))

if len(cards)==1:
    print(0)
else:
    while len(cards)>1:
        first = heapq.heappop(cards)
        second = heapq.heappop(cards)
        plus = first+second
        answer+=plus
        heapq.heappush(cards,plus)
print(answer)