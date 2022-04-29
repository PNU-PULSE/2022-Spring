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
#define MAX_N 10005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n;

int tet[2][6][4];

int score;

bool checkPlacible(int arr[6][4], int t, int y, int x) {
    switch(t) {
        case 1:
            return !arr[y][x];
        case 2:
            return !arr[y][x] && !arr[y][x + 1];
        case 3:
            return !arr[y][x] && !arr[y - 1][x];
    }
}

void place(int arr[6][4], int t, int x, int value) {
    int y;
    for (y = 2; y <= 5; ++y) {
        bool placible = checkPlacible(arr, t, y, x);
        if (!placible) break;
    }
    --y;

    switch(t) {
        case 1:
            arr[y][x] = value;
            break;
        case 2:
            arr[y][x] = value;
            arr[y][x + 1] = -value;
            break;
        case 3:
            arr[y][x] = value;
            arr[y - 1][x] = value;
            break;
    }
}

bool check(int arr[6][4]) {
    bool ret = false;
    for (int i = 2; i < 6; ++i) {
        if (arr[i][0] && arr[i][1] && arr[i][2] && arr[i][3]) {
            for (int j = 0; j < 4; ++j) {
                arr[i][j] = 0;
            }
            ++score;
            ret = true;
        }
    }
    return ret;
}

void move(int arr[6][4]) {
    while (true) {
        bool flag = false;
        for (int i = 4; i >= 1; --i) {
            for (int j = 0; j < 4; ++j) {
                if (arr[i][j] > 0 && !arr[i + 1][j]) {
                    if (j != 3 && (arr[i][j + 1] == -arr[i][j])) {
                        if (!arr[i + 1][j + 1]) {
                            arr[i + 1][j] = arr[i][j];
                            arr[i][j] = 0;
                            arr[i + 1][j + 1] = arr[i][j + 1];
                            arr[i][j + 1] = 0;
                            flag = true;
                        }
                    } else {
                        arr[i + 1][j] = arr[i][j];
                        arr[i][j] = 0;
                        flag = true;
                    }
                }
            }
        }
        if (!flag) break;
    }
}

void pack(int arr[6][4]) {
    for (int i = 0; i < 2; ++i) {
        if (arr[i][0] || arr[i][1] || arr[i][2] || arr[i][3]) {
            for (int j = 5; j >= 1; --j) {
                for (int k = 0; k < 4; ++k) {
                    arr[j][k] = arr[j - 1][k];
                    arr[j - 1][k] = 0;
                }
            }
        }
    }
}

int getTileCnt(int arr[6][4]) {
    int ret = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (arr[i][j]) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t, x, y;
        cin >> t >> y >> x;

        place(tet[0], t, x, i);
        place(tet[1], (4 - t) % 3 + 1, y, i);

        for (int j = 0; j < 2; ++j) {
            while(check(tet[j])) {
                move(tet[j]);
            }
            pack(tet[j]);
        }
    }
    cout << score << endl;
    cout << getTileCnt(tet[0]) + getTileCnt(tet[1]) << endl;

    return 0;
}