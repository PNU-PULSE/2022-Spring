//효율성 통과 실패...

#include <string>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> R;
    list<int> S;
    int a;
    string answer = "";
    for(int i = 0; i < n; i++){
        answer += 'O';
        S.push_back(i);
    }
    auto idx = S.begin();
    auto val = S.begin();
    advance(idx, k);
    for(auto x : cmd){
        switch(x[0]){
            case 'U':
                a = stoi(x.substr(2));
                advance(idx, -a);
                break;
            case 'D':
                a = stoi(x.substr(2));
                advance(idx, a);
                break;
            case 'C':
                R.push(*idx);
                answer[*idx] = 'X';
                idx = S.erase(idx);
                if (idx == S.end()) idx--;
                break;
            case 'Z':
                val = upper_bound(S.begin(), S.end(), R.top());
                S.insert(val, R.top());
                answer[R.top()] = 'O';
                R.pop();
                break;
            default:
                break;
        }
    }
    return answer;
}
