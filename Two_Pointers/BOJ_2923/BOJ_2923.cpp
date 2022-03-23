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
#define MAX_N 105
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n;
int a[MAX_N];
int b[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int ta, tb;
        cin >> ta >> tb;
        a[ta]++;
        b[tb]++;

        int ans = 0;
        int l = 0, r = 100;
        int acopy[MAX_N];
        int bcopy[MAX_N];
        memcpy(acopy, a, sizeof(acopy));
        memcpy(bcopy, b, sizeof(bcopy));
        while(l <= 100 && r >= 0) {
            if (acopy[l] == 0) ++l;
            else if (bcopy[r] == 0) --r;
            else {
                if (acopy[l] > bcopy[r]) {
                    acopy[l] -= bcopy[r];
                    bcopy[r] = 0;
                    ans = max(ans, l + r);
                    --r;
                } else {
                    bcopy[r] -= acopy[l];
                    acopy[l] = 0;
                    ans = max(ans, l + r);
                    ++l;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}