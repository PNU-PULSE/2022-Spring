#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> m;
vector<vector<int>> m_exp;
vector<pair<int, int>> M_list;
queue<pair<int, int>> q;
int N, M, fuel, pre_fuel;
int cx[4] = {-1, 0, 0, 1};
int cy[4] = {0, -1, 1, 0};

int bfs(int M_dt) {
    int x, y;
    bool f = 0;

    if (M_dt == 0) {
        int tx = -1, ty = -1;
        int temp_fuel = 0;

        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if (f == 1 && m_exp[x][y] < temp_fuel) break;
            else if (m[x][y] < 0) {
                f = 1;
                temp_fuel = m_exp[x][y];
                if (tx == -1) {
                    tx = x; ty = y;
                }
                else {
                    if (tx > x) {
                        tx = x; ty = y;
                    }
                    else if (tx == x) {
                        if (ty > y) {
                            tx = x; ty = y;
                        }
                    }
                }
            }
            else if (m_exp[x][y] > 0) {
                for (int i = 0; i < 4; i++) {
                    if (x + cx[i] >= 0 && x + cx[i] < N && y + cy[i] >= 0 && y + cy[i] < N) {
                        if (m[x + cx[i]][y + cy[i]] != 1 && m_exp[x + cx[i]][y + cy[i]] == 0) {
                            q.push({x + cx[i], y + cy[i]});
                            m_exp[x + cx[i]][y + cy[i]] = m_exp[x][y] - 1;
                        }
                    }
                }
            }
        }

        if (f) {
            int M_temp = m[tx][ty];
            m[tx][ty] = 0;
            while (!q.empty()) q.pop();
            q.push({tx, ty});

            fuel = m_exp[tx][ty];
            pre_fuel = fuel;

            m_exp.assign(N, vector<int>(N));
            m_exp[tx][ty] = fuel;

            return bfs(M_temp);
        }
        else return 0;
    }

    else {
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if (x == M_list[-M_dt].first && y == M_list[-M_dt].second) {
                f = 1;
                break;
            }
            else if (m_exp[x][y] > 0) {
                for (int i = 0; i < 4; i++) {
                    if (x + cx[i] >= 0 && x + cx[i] < N && y + cy[i] >= 0 && y + cy[i] < N) {
                        if (m[x + cx[i]][y + cy[i]] != 1 && m_exp[x + cx[i]][y + cy[i]] == 0) {
                            q.push({x + cx[i], y + cy[i]});
                            m_exp[x + cx[i]][y + cy[i]] = m_exp[x][y] - 1;
                        }
                    }
                }
            }
        }

        if (f) {
            int M_temp = m[x][y];

            while (!q.empty()) q.pop();
            q.push({x, y});

            fuel = (pre_fuel - m_exp[x][y]) * 2 + m_exp[x][y];

            m_exp.assign(N, vector<int>(N));
            m_exp[x][y] = fuel;
            M--;
            return 1;
        }
        else return 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> fuel;

	m.assign(N, vector<int>(N));
	M_list.assign(M + 1, {0, 0});
	m_exp.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }

    int x, y;

    cin >> x >> y;

    q.push({x - 1, y - 1});
    m_exp[x - 1][y - 1] = fuel;

    for (int i = 1; i <= M; i++) {
        cin >> x >> y;
        m[x - 1][y - 1] = -i;

        cin >> x >> y;
        M_list[i] = {x - 1, y - 1};
    }

    while (M > 0) {
        if (bfs(0) == 0) break;
    }

    if (M == 0) cout << fuel;
    else cout << -1;
}

