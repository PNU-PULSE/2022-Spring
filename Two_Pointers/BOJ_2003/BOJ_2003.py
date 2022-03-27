n,m = map(int,input().split())
array = list(map(int,input().split()))
start = 0
end = 1
answer = 0
while end<=n and start<=end:
    total = sum(array[start:end])
    if total ==m:
        answer +=1
        end+=1
    elif total <m:
        end+=1
    elif total>m:
        start+=1
    

print(start,end,answer)