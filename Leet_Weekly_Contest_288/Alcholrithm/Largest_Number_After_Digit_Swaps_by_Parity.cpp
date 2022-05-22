class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd, even;
        stack<int> s;

        while(num>0) {
            int n = num % 10;
            num /=10;
            s.push(n);
            if (n%2==0) {
                even.push_back(n);
            }
            else {
                odd.push_back(n);
            }
        }
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        int o = 0, e = 0;
        int res = 0;
        while(o < odd.size() && e < even.size()) {
            int top = s.top();
            s.pop();
            res *= 10;
            if (top%2 == 0) {
                res += even[e++];
            }
            else {
                res += odd[o++];
            }
        }
        while (o < odd.size()){
            res *= 10;
            res += odd[o++];
        }
        while (e < even.size()) {
            res *= 10;
            res += even[e++];
        }
        return res;
    }
};