#include <iostream>
#include <queue>

using namespace std;

int N, M;

void BFS(vector<vector<int>> path) {
    vector<int> dist(N, -1);

    queue<int> q;
    q.push(0);
    dist[0] = 0;

    int even = 1, odd = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i=0; i<path[cur].size(); i++) {
            int next = path[cur][i];
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
                if (dist[next] % 2 == 1) odd++;
                else even++;
            }
            else if (dist[next] % 2 == dist[cur] % 2) {
                cout << 0 << endl;
                return;
            }
        }
    }

    cout << (odd * even * 2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> path(N);
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        path[a-1].push_back(b-1);
        path[b-1].push_back(a-1);
    }

    BFS(path);
}
