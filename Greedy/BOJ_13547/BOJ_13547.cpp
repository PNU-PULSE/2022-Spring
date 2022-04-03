/********* github.com/tykr0001/algorithm *********\
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
*$*                                             *$*
*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*
*$*       ||      ||  ||   || |||    ||    ||   *$*
*$*       ||        ||     |||       |||||||    *$*
*$*       ||        ||     || |||    ||  ||     *$*
*$*       ||        ||     ||   |||  ||   |||   *$*
*$*                                             *$*
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
\*************  2022-04-02 14:34:02  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;
using vs = vector<string>;
using v2s = vector<vs>;
using vc = vector<char>;
using v2c = vector<vc>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T1, typename T2>
void sort(T1& container, T2 cmp) { sort(container.begin(), container.end(), cmp); }
template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... Size>
void resize(T& container, int _size, Size... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

int r, c;
int arr[1001][1001];
string ans;

int min_val = INF;
int min_i;
int min_j;

string Rep(char c, int n) {
    string ret = "";
    while (n--) ret += c;
    return ret;
}

void Solve(void) {
    if (r % 2) {
        for (int i = 0; i < r; i++) {
            if (i % 2 == 0)
                ans += Rep('R', c - 1);
            else
                ans += Rep('L', c - 1);
            if (i != r - 1)
                ans += 'D';
        }
    }
    else if (c % 2) {
        for (int j = 0; j < c; j++) {
            if (j % 2 == 0)
                ans += Rep('D', r - 1);
            else
                ans += Rep('U', r - 1);
            if (j != c - 1)
                ans += 'R';
        }
    }
    else {
        bool flag = false;
        for (int i = 0; i < r; i += 2) {
            if (min_i == i || min_i == i + 1) {
                bool zigzag = false; // true : up, false : down,
                flag = true;
                for (int j = 0; j < c; j++) {
                    if (min_j != j) {
                        if (zigzag) ans += 'U';
                        else ans += 'D';
                        zigzag = !zigzag;
                    }
                    if (j != c - 1)
                        ans += 'R';
                }
                if (i != r - 2)
                    ans += 'D';
            }
            else {
                if (flag) {
                    ans += Rep('L', c - 1);
                    ans += 'D';
                    ans += Rep('R', c - 1);
                }
                else {
                    ans += Rep('R', c - 1);
                    ans += 'D';
                    ans += Rep('L', c - 1);
                }
                if (i != r - 2)
                    ans += 'D';
            }
        }
    }

    cout << ans;
}

void Init(void) {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if ((i + j) % 2 && min_val > arr[i][j]) {
                min_val = arr[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}