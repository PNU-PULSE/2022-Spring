class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        int i = 0;

        while (true) {
            odd.push_back(nums[i++]);
            if (i == nums.size()) break;
            even.push_back(nums[i++]);
            if (i == nums.size()) break;
        }

        sort(odd.begin(), odd.end(), less<>());
        sort(even.begin(), even.end(), greater<>());

        vector<int> ans(nums.size());

        i = 0;
        int j = 0;
        while (true) {
            ans[i++] = odd[j];
            if (i == nums.size()) break;
            ans[i++] = even[j];
            if (i == nums.size()) break;
            j++;
        }
        return ans;
    }
};
