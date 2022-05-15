class Solution {
public:
    long long smallestNumber(long long num) {
        int digit[10] = {0};
        bool t = 0;
        long long Sol = 0;
        
        if (num < 0) {
            t = 1;
            num = -num;
        }
        
        while (num > 0) {
            digit[num % 10]++;
            num /= 10;
        }
        
        if (!t) {
            for (int i = 1; i < 10; i++) {
                if (digit[i] > 0) {
                    Sol += i;
                    digit[i]--;
                    break;
                }
            }
            
            for (int i = 0; i < 10; i++) {
                while (digit[i] > 0) {
                    Sol = Sol * 10 + i;
                    digit[i]--;
                }
            }
        }
        
        else {
            for (int i = 9; i > 0; i--) {
                if (digit[i] > 0) {
                    Sol += i;
                    digit[i]--;
                    break;
                }
            }
            
            for (int i = 9; i >= 0; i--) {
                while (digit[i] > 0) {
                    Sol = Sol * 10 + i;
                    digit[i]--;
                }
            }
            
            Sol = -Sol;
        }
        
        return Sol;
    }
};
