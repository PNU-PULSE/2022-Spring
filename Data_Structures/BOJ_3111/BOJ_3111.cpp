#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
    os << pai.first << ' ' << pai.second;
    return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
    is >> pai.first >> pai.second;
    return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 500005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

string a, b, tTemp;
deque<char> t;

stack<pair<char, vector<int>>> st1, st2;

vector<int> calculate(stack<pair<char, vector<int>>>& st, string& str, char value) {
    if (st.empty()) {
        if (str[0] == value) {
            return {0};
        } else {
            return {-1};
        }
    } else {
        vector<int> result;
        if (str[0] == value) {
            result.push_back(0);
        }
        for (int i = 0; i < st.top().second.size(); ++i) {
            if (st.top().second[i] + 1 != str.size() && str[st.top().second[i] + 1] == value) {
                result.emplace_back(st.top().second[i] + 1);
            }
        }
        if (result.size() == 0) {
            return {-1};
        } else {
            sort(all(result));
            return result;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> tTemp;
    for (int i = a.size() - 1; i >= 0; --i)
        b.push_back(a[i]);
    for (auto c : tTemp) {
        t.emplace_back(c);
    }

    while(true) {
        // front
        bool frontFound = false;
        while (true) {
            // case 1: [front] deque가 남아 있을 때
            if (t.size()){
                st1.emplace(t.front(), calculate(st1, a, t.front()));
                t.pop_front();
            }
            // case 2: [front] deque가 남아 있지 않을 때
            else {
                if (st2.empty()) {
                    break;
                }
                st1.emplace(st2.top().first, calculate(st1, a, st2.top().first));
                st2.pop();
            }

            // check
            if (st1.top().second.back() == (int)a.size() - 1) {
                int temp = a.size();
                while(temp--) st1.pop();
                frontFound = true;
                break;
            }
        }
        if (frontFound == false) break;
        
        bool backFound = false;
        while (true) {
            // case 1: [back] deque가 남아 있을 때
            if (t.size()){
                st2.emplace(t.back(), calculate(st2, b, t.back()));
                t.pop_back();
            }
            // case 2: [back] deque가 남아 있지 않을 때
            else {
                if (st1.empty()) {
                    break;
                }
                st2.emplace(st1.top().first, calculate(st2, b, st1.top().first));
                st1.pop();
            }

            // check
            if (st2.top().second.back() == (int)a.size() - 1) {
                int temp = a.size();
                while(temp--) st2.pop();
                backFound = true;
                break;
            }
        }
        if (backFound == false) break;
    }

    while(st1.size()) {
        st2.emplace(st1.top());
        st1.pop();
    }

    while(st2.size()) {
        cout << (char)st2.top().first;
        st2.pop();
    }

    
    return 0;
}
