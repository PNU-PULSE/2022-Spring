def solution(s):
    result = ""
    num = ""
    nums = {'zero': '0', 'one': '1', 'two': '2', 'three': '3', 'four': '4',
            'five': '5', 'six': '6', 'seven': '7', 'eight': '8', 'nine': '9'}
    for i in s:
        if i.isdecimal():
            result += i
        else:
            num += i
            if num in nums:
                result += nums[num]
                num = ""
    return int(result)