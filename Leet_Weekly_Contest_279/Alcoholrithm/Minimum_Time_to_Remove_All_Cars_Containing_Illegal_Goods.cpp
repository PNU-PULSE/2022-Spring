class Solution {
public:
    int minimumTime(string s) {
        int len = s.length();
        vector<int> pre_sum(len);
        pre_sum[0] = s[0] == '1' ? 1 : 0;
        for(int i = 1; i < len; ++i) {
            pre_sum[i] = s[i] == '1' ? min(pre_sum[i - 1] + 2, i + 1) : pre_sum[i - 1];
        }
        
        vector<int> suf_sum(len);
        suf_sum[len - 1] = s[len - 1] == '1' ? 1 : 0;
        for(int i = len - 2; i >= 0; --i) {
            if (s[i] == '1') {
                suf_sum[i] = min(suf_sum[i + 1] + 2, len - i);
            }
            else {
                suf_sum[i] = suf_sum[i + 1];
            }
        }
        int ans = min(pre_sum[len - 1], suf_sum[0]);
        for(int i = 0; i< len - 1; ++i) {
            ans = min(ans, pre_sum[i] + suf_sum[i + 1]);
        }
        
        return ans;
    }
};