class Solution {
public:
    int minimumTime(string s) {
        int start = 0;
        int n = s.length();
        int result = n;
        for(int i = 0; i < n; i++){
            start = min(start + (s[i] - '0') * 2, i + 1);
            result = min(result, start + n - i - 1);
        }
        return result;
    }
};
