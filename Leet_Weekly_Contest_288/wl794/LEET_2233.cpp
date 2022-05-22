class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int idx = 0;
        int cur = nums[0];
        while (k--) {
            nums[idx] += 1;
            idx++;
            if (idx == nums.size() || nums[idx] != cur) {
                idx = 0;
                cur = nums[0];
            }
        }

        int ret = nums[0];
        for (int i=1; i<nums.size(); i++) {
            ret = (1LL * ret * nums[i]) % 1000000007;
        }
        return ret;
    }
};
