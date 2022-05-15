class Solution {
public:
    int minimumTime(string s) {
        int L = s[0] - '0';
        int m = L + s.length() - 1;

        for (int i = 1; i < s.length(); i++) {
            L = min(L + (s[i] == '1' ? 2 : 0), i + 1);
            if (L + s.length() - i - 1 < m) m = L + s.length() - i - 1;
        }

        return m;
    }
};
