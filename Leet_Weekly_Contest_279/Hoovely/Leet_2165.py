# leetcode 2165
# 주어지는 숫자의 자릿수를 재 배열해서 만들 수 있는 가장 작은 수 출력
# 맨 앞이 0이 오면 안됌

class Solution:
    def smallestNumber(self, num: int) -> int:
        if num == 0:
            return 0

        lst_num = []
        for i in str(num):
            if i == '-':
                continue
            lst_num.append(int(i))
        if num > 0:
            lst_num.sort()
            SmallestNum = ""
            cnt = 0
            for i in range(len(lst_num)):
                if lst_num[i] == 0:
                    cnt += 1
                else:
                    if cnt:
                        SmallestNum = str(lst_num[i]) + "0"*cnt
                        cnt = 0
                        continue
                    SmallestNum += str(lst_num[i])
            return int(SmallestNum)
        else:
            lst_num.sort(reverse=True)
            SmallestNum = "-"
            for i in range(len(lst_num)):
                SmallestNum += str(lst_num[i])
            return int(SmallestNum)
