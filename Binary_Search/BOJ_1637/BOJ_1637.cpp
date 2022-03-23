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
#define MAX_N 20005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n;
int a[MAX_N];
int b[MAX_N];
int c[MAX_N];

bool check(ll mid) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (mid < a[i]) continue;

        if (mid > c[i]) {
            sum += (c[i] - a[i]) / b[i] + 1;
        }
        else {
            sum += (mid - a[i]) / b[i] + 1; 
        }
    }
    return sum % 2 == 0;
}

int parametric_search() {
    ll l = 1, r = INT_MAX;
    while(l < r) {
        ll mid = (l + r) / 2;
        if (check(mid) == false) r = mid;
        else l = mid + 1; 
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> c[i] >> b[i];
    }

    int ans = parametric_search();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] < ans || ans < a[i]) continue;
        if ((ans - a[i]) % b[i] == 0) ++ cnt;
    }
    if (cnt == 0) cout << "NOTHING" << endl;
    else cout << pii(ans, cnt) << endl;
    
    return 0;
}