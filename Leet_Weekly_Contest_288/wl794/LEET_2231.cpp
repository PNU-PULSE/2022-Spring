class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odds;
        priority_queue<int> evens;
        vector<int> flag;

        while (num > 0) {
            int a = num % 10;
            num /= 10;
            if (a % 2 == 1) {
                odds.push(a);
                flag.push_back(1);
            }
            else {
                evens.push(a);
                flag.push_back(0);
            }
        }

        int ret = 0;
        for (int i=flag.size()-1; i>=0; i--) {
            ret *= 10;
            if (flag[i] == 1) {
                ret += odds.top();
                odds.pop();
            }
            else if (flag[i] == 0) {
                ret += evens.top();
                evens.pop();
            }
        }

        return ret;
    }
};
