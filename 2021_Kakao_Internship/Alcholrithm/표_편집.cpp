#include <stack>
#include <vector>
#include <set>
#include <string>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer;
    set<int> s;
    stack<int> erased;

    for(int i = 0; i < n; ++i) {
        s.insert(i);
    }
    auto it = s.find(k);
    for(auto q : cmd) {
        int x = 0;
        switch (q[0]) {
            case 'U':
                for(int i = 2; i < q.size(); ++i) {
                    x = x * 10 + q[i] - '0';
                }
                while(x--) {
                    it--;
                }
                break;
            case 'D':
                for(int i = 2; i < q.size(); ++i) {
                    x = x* 10 + q[i] - '0';
                }
                while(x--) {
                    it++;
                }
                break;
            case 'C':
                erased.push(*it);
                if(*it == *s.rbegin()) {
                    it--;
                }
                else {
                    it++;
                }
                s.erase(erased.top());
                break;
            default:
                s.insert(erased.top());
                erased.pop();
        }
    }

    vector<bool> check(n);
    for(auto i : s) {
        check[i] = true;
    }
    for(int i = 0; i< n; ++i) {
        if (check[i]) {
            answer += 'O';
        }
        else {
            answer += 'X';
        }
    }
    return answer;
}