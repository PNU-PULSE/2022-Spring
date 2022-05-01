#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> m;
vector<vector<int>> m_exp;
priority_queue<pair<int, int>> fish_list;
queue<pair<int, int>> q;
int N, shark_size = 2, shark_ate = 0, dis = 0;
int cx[4] = {-1, 0, 0, 1};
int cy[4] = {0, -1, 1, 0};

void bfs() {
    int x, y, f = 0;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (f != 0 && m_exp[x][y] > f) break;
        else if (m[x][y] != 0 && m[x][y] < shark_size) {
            fish_list.push({-x, -y});
            f = m_exp[x][y];
        }
        else {
            for (int i = 0; i < 4; i++) {
                if (x + cx[i] >= 0 && x + cx[i] < N && y + cy[i] >= 0 && y + cy[i] < N) {
                    if (m_exp[x + cx[i]][y + cy[i]] == 0 && m[x + cx[i]][y + cy[i]] <= shark_size) {
                        q.push({x + cx[i], y + cy[i]});
                        m_exp[x + cx[i]][y + cy[i]] = m_exp[x][y] + 1;
                    }
                }
            }
        }
    }

    if (f != 0) {
        dis += f - 1;
        shark_ate++;
        if (shark_size == shark_ate) {
            shark_size++;
            shark_ate = 0;
        }

        m[-fish_list.top().first][-fish_list.top().second] = 0;
        m_exp.assign(N, vector<int>(N));
        m_exp[-fish_list.top().first][-fish_list.top().second] = 1;

        while (!q.empty()) q.pop();
        q.push({-fish_list.top().first, -fish_list.top().second});

        while (!fish_list.empty()) fish_list.pop();

        f = 0;
        bfs();
    }
}

void fun_assign() {
    cin >> N;
    m.assign(N, vector<int>(N));
	m_exp.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];

            if (m[i][j] == 9) {
                m[i][j] = 0;
                m_exp[i][j] = 1;
                q.push({i, j});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    fun_assign();
    bfs();
    cout << dis;
}

