# leetcode 2164
# 홀수 인덱스 => 내림차순 정렬
# 짝수 인덱스 => 오름차순 정렬

class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        if len(nums) <= 2:
            return nums

        odd_nums = []  # 홀수
        even_nums = []  # 짝수
        for i in range(len(nums)):
            if i % 2 == 0:
                even_nums.append(nums[i])
            else:
                odd_nums.append(nums[i])
        odd_nums.sort(reverse=True)
        even_nums.sort()

        for i in range(len(nums)):
            if i % 2 == 0:
                nums[i] = even_nums[i//2]
            else:
                nums[i] = odd_nums[i//2]

        return nums
