class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd;
        vector<int> even;
        vector<int> check;
        int o = 0, e = 0, result = 0;
        while(num != 0){
            int n = num % 10;
            if(n % 2 == 0){
                even.push_back(n);
                check.push_back(1);
            }
            else{
                odd.push_back(n);
                check.push_back(0);
            }
            num /= 10;
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        reverse(check.begin(), check.end());
        for(auto x : check){
            result *= 10;
            if(x == 0) result += odd[o++];
            else result += even[e++];
        }
        return result;
    }
};
