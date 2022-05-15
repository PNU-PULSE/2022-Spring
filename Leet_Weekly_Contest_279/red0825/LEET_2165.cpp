class Solution {
public:
    long long smallestNumber(long long num) {
        int nums[20];
        int i = 0;
        int check = 0;
        int check2 = 0;
        int minVal = 10;
        long long result = 0;
        if(num < 0) check = 1;
        num = abs(num);
        while(num){
            nums[i] = num % 10;
            if(nums[i] != 0 && minVal > nums[i]) minVal = nums[i];
            i++;
            num /= 10;
        }
        if(check){
            sort(nums, nums + i);
            long long tens = 1;
            for(int j = 0; j < i; j++){
                result += nums[j]*tens;
                tens *= 10;
            }
            result *= -1;
        }
        else{
            sort(nums, nums + i, greater<int>());
            long long tens = 1;
            int j;
            for(j = 0; j < i; j++){
                if(nums[j] < minVal){
                    result -= nums[j - 1]*tens/10;
                    check2 = 1;
                    break;
                }
                result += nums[j]*tens;
                tens *= 10;
            }
            for(; j < i - 1; j++){
                tens *= 10;
            }
            if(check2 == 1) result += minVal*tens;
        }
        return result;
    }
};
