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
#define MAX_N 2005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int parent[MAX_N * MAX_N];
int level[MAX_N * MAX_N];
int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return;
    if (level[u] > level[v]) 
        swap(u, v);
    if (level[u] == level[v]) {
        level[v]++;
    }
    parent[u] = v;
}

int n, m;
char arr[MAX_N][MAX_N];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void buildFire() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
                if (arr[i][j] != 0 || arr[ny][nx] != 0) continue;
                merge(i * m + j, ny * m + nx);
            }
        }
    }
}

deque<pii> q;
void run() {

    int fireCnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 0){
                q.emplace_back(i, j); 
                ++fireCnt;
            }
        }
    }
    int time = 0;
    pii ans = {0, fireCnt};
    while(true) {
        for (int i = 0; i < q.size(); ++i) {
            int hy = q[i].first;
            int hx = q[i].second;

            for (int j = 0; j < 4; ++j) {
                int ny = hy + dy[j];
                int nx = hx + dx[j];

                if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
                if (arr[ny][nx] != 0) continue;
                if (find(hy * m + hx) != find(ny * m + nx)) {
                    merge(hy * m + hx, ny * m + nx);
                    ans = pii(time, fireCnt);
                }
                
            }   
        }

        int qsize = q.size();
        while(qsize--) {
            int hy = q.front().first;
            int hx = q.front().second;
            q.pop_front();

            for (int i = 0; i < 4; ++i) {
                int ny = hy + dy[i];
                int nx = hx + dx[i];

                if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
                if (arr[ny][nx] != 1) continue;
                q.emplace_back(ny, nx);
                ++fireCnt;
                merge(ny * m + nx, hy * m + hx);
                arr[ny][nx] = 0; 
            }
        }
        if (q.empty()) {
            break;
        }

        ++time;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < MAX_N * MAX_N; ++i)
        parent[i] = i;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            arr[i][j] -= '0';
        }
    }

    buildFire();
    run();
    
    return 0;
}