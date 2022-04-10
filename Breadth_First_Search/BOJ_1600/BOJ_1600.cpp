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
\*************  2022-04-04 21:58:10  *************/

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

int k, w, h;
v2i arr;

int di[4] = { 0, 0, -1, 1 };
int dj[4] = { 1, -1, 0, 0 };
int jump_di[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int jump_dj[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

struct Node {
    int i;
    int j;
    int move; // ?? ??
    int jump; // ?? ??
};

bool CanGo(int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w&& arr[i][j] != 1;
}

void BFS() {
    queue<Node> q;
    q.emplace(Node { 0,0,0,0 });
    v3i visited;
    resize(visited, h, w, k + 1);
    visited[0][0][0] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.i == h - 1 && cur.j == w - 1) {
            cout << cur.move << endl;
            return;
        }

        if (cur.jump < k) {
            for (int idx = 0; idx < 8; idx++) {
                int i = cur.i + jump_di[idx];
                int j = cur.j + jump_dj[idx];
                int move = cur.move + 1;
                int jump = cur.jump + 1;
                if (CanGo(i, j) && !arr[i][j] && !visited[i][j][jump]) {
                    visited[i][j][jump] = 1;
                    q.emplace(Node { i,j,move,jump });
                }
            }
        }

        for (int idx = 0; idx < 4; idx++) {
            int i = cur.i + di[idx];
            int j = cur.j + dj[idx];
            int move = cur.move + 1;
            int jump = cur.jump;
            if (CanGo(i, j) && !arr[i][j] && !visited[i][j][jump]) {
                visited[i][j][jump] = 1;
                q.emplace(Node { i,j,move,jump });
            }
        }
    }
    cout << -1 << endl;
}

void Solve(void) {
    BFS();
}

void Init(void) {
    cin >> k >> w >> h;
    resize(arr, h, w);
    cin >> arr;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}