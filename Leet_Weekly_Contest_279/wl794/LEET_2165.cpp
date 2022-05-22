#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        bool minus = (num < 0);
        if (minus) num = -num;

        int zeros = 0;
        vector<int> v;
        while (num > 0) {
            if (num % 10 == 0) zeros++;
            else v.push_back (num % 10);
            num /= 10;
        }

        if (minus) sort(v.begin(), v.end(), greater<>());
        else sort(v.begin(), v.end(), less<>());

        long long ans = 0;
        // 0 조건 추가 이거 없으면 밑에서 무한루프 떠서 런타임 에러 남
        if (v.size() == 0) {
            return 0;
        }
        else if (!minus) {
            ans = v[0];
            while (zeros != 0) {
                ans *= 10;
                zeros--;
            }
            int i = 1;
            while (i != v.size()) {
                ans *= 10;
                ans += v[i++];
            }
        }
        else {
            ans = v[0];
            int i = 1;
            while (i != v.size()) {
                ans *= 10;
                ans += v[i++];
            }
            while (zeros != 0) {
                ans *= 10;
                zeros--;
            }
            ans = -ans;
        }
        return ans;
    }
};

int main() {
    long long ll;
    cin >> ll;
    Solution sol;
    cout << sol.smallestNumber(ll);
}
