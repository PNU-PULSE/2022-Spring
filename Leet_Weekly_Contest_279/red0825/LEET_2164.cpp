class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> Even;
        vector<int> Even_index;
        vector<int> Odd;
        vector<int> Odd_index;
        int i = 0;
        for(auto x : nums){
            if(i % 2 == 0){
                Even.push_back(x);
                Even_index.push_back(i);
            }
            else{
                Odd.push_back(x);
                Odd_index.push_back(i);
            }
            i++;
        }
        sort(Even.begin(), Even.end());
        sort(Odd.begin(), Odd.end(), greater<int>());
        i = 0;
        for(auto x : Even_index){
            nums[x] = Even[i];
            i++;
        }
        i = 0;
        for(auto x : Odd_index){
            nums[x] = Odd[i];
            i++;
        }
        return nums;
    }
};
