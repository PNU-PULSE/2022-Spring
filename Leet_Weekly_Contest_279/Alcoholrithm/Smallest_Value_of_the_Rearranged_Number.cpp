class Solution {
public:
    long long smallestNumber(long long num) {
        bool sign = num > 0 ? true : false;
        num = abs(num);
        vector<int> digits;
        long long origin = 0;
        int temp = 0;
        long long temp2 = num;
        while(origin != temp2) {
            origin += (num %10) * pow(10, temp++);
            digits.push_back(num%10);
            num /= 10;
        }
        

        if (!sign) {
            sort(digits.begin(), digits.end(), greater<int>());
        }
        else {
            sort(digits.begin(), digits.end());

            for(int i = 0; i < digits.size(); ++i) {
                if (digits[i] != 0 && digits[0] == 0) {
                    digits[0] = digits[i];
                    digits[i] = 0;
                }
            }
        }
       
        long long res = 0;
        for(int i = 0; i < digits.size(); ++i) {
            res*=10;
            res += digits[i];
        }
        if (!sign) {
            res = res * -1;
        }
        return res;
    }
};