class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> Odd;
        vector<int> Even;
        vector<int> Sol;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 1) Odd.push_back(nums[i]);
            else Even.push_back(nums[i]);
        }
        
        sort(Even.begin(), Even.end());
        sort(Odd.begin(), Odd.end(), greater<int>());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 1) Sol.push_back(Odd[i / 2]);
            else Sol.push_back(Even[i / 2]);
        }
     
        return Sol;
    }
};
