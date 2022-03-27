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
\*************  2022-03-27 16:16:19  *************/

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

// Segment-Tree(세그먼트트리)
struct Segment {
    vl arr;
    v2l sub_arr;

    Segment() { }
    Segment(int n) : arr(n + 1), sub_arr(1 << int(ceil(log2(n))) + 1) { }

    // fix the Args start at 1, end at n
    // O(n log n)
    void Init(int node, int start, int end) {
        if (start == end) {
            sub_arr[node].push_back(arr[start]);
            return;
        }
        Init(node * 2, start, (start + end) / 2);
        Init(node * 2 + 1, (start + end) / 2 + 1, end);

        // std:merge reference : https://www.cplusplus.com/reference/algorithm/merge/
        sub_arr[node].resize(sub_arr[node * 2].size() + sub_arr[node * 2 + 1].size());
        merge(sub_arr[node * 2].begin(), sub_arr[node * 2].end(), sub_arr[node * 2 + 1].begin(), sub_arr[node * 2 + 1].end(), sub_arr[node].begin());
    }

    // arr[left...right] 중 mid 이하의 수 갯수 반환
    // O(log^2 n)
    ll Query(int node, int start, int end, ll left, ll right, ll mid) {
        // [left...right] 범위와 전혀 겹치지 않는 노드
        if (left > end || right < start)
            return 0;

        // O(log n)
        // [left...right] 범위에 완전히 포함되는 노드
        if (left <= start && end <= right)
            return upper_bound(sub_arr[node].begin(), sub_arr[node].end(), mid) - sub_arr[node].begin();

        // O(log n)
        // [left...right] 범위와 일부 겹치는 노드
        return Query(node * 2, start, (start + end) / 2, left, right, mid)
             + Query(node * 2 + 1, (start + end) / 2 + 1, end, left, right, mid);
    }
} seg;

int n, m;

void Solve(void) {
    while (m--) {
        // O(m)
        ll i, j, k;
        cin >> i >> j >> k;
        ll lo = -1e9;
        ll hi = 1e9;
        // O(log n)
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;

            // O(log^2 n)
            // 정렬된 a[i...j]에서 mid 이하의 수가 k개 미만
            if (seg.Query(1, 1, n, i, j, mid) < k)
                lo = mid + 1;
            // 정렬된 a[i...j]에서 mid 이하의 수가 k개 이상
            else if (seg.Query(1, 1, n, i, j, mid) >= k)
                hi = mid - 1;
        }
        cout << lo << endl;
    }
}

void Init(void) {
    cin >> n >> m;
    seg = Segment(n);
    for (int i = 1; i <= n; i++) {
        cin >> seg.arr[i];
    }
    // O(n log n)
    seg.Init(1, 1, n);
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}