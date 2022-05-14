class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even, odd;
        for(int i = 0; i < nums.size();++i) {
            if (i%2==0) {
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end(), greater<int>());
        vector<int> res;
        for(int i = 0, o = 0, e = 0; i < nums.size(); ++i) {
            if (i%2 == 0) {
                res.push_back(odd[o++]);
            }
            else{
                res.push_back(even[e++]);
            }
        }
        return res;
    }
};