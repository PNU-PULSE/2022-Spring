#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    vector<int> v(n);
    for (int i=0; i<n; i++) v[i] = i;

    stack<int> deleted;

    for (string s: cmd) {
        //answer += (k + '0');
        if (s[0] == 'U') {
            int x = stoi(s.substr(2));
            k -= x;
        } else if (s[0] == 'D') {
            int x = stoi(s.substr(2));
            k += x;
        } else if (s[0] == 'C') {
            deleted.push(v[k]);
            if (v.begin() + k != v.end())
                v.erase(v.begin() + k);
            if (k == v.size()) {
                k--;
            }
        } else {
            int del = deleted.top();
            auto pos = upper_bound(v.begin(), v.end(), del);
            v.insert(pos, del);
            deleted.pop();
            if (del < k) k++;
        }
    }

    int idx = 0;
    for (int i=0; i<n; i++) {
        if (idx == v.size()) {
            answer += ('X');
        }
        else if (v[idx] == i) {
            answer += ('O');
            idx++;
        }
        else {
            answer += ('X');
        }
    }

    return answer;
}
