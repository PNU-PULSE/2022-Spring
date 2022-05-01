#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[50][50];
bool visited[50][50];
bool height_visited[50][50];
bool visited_tmp[50][50];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void init_arr(bool v[50][50]) {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            v[i][j] = false;
}

pair<int, int> find_pos(int height) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visited[i][j] && !height_visited[i][j] && arr[i][j] <= height)
                return {i, j};
        }
    }
    return {-1, -1};
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++)
            arr[i][j] = s[j] - '0';
    }


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == m-1) visited[i][j] = true;
            if (arr[i][j] == 0) visited[i][j] = true;
        }
    }

    int sum = 0;
    for (int height=2; height<=9; height++) {
        init_arr(height_visited);

        while (true) {
            pair<int, int> start = find_pos(height-1);
            if (start.first == -1) break;

            bool end_flag = false;

            queue<pair<int, int>> q;
            q.push(start);

            init_arr(visited_tmp);
            visited_tmp[start.first][start.second] = true;
            height_visited[start.first][start.second] = true;
            int cnt = 1;

            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int i=0; i<4; i++) {
                    int ny = cur.first + dy[i];
                    int nx = cur.second + dx[i];
                    if (nx < 0 || nx >= m || ny < 0  || ny >= n) continue;
                    if (visited_tmp[ny][nx]) continue;
                    if (arr[ny][nx] >= height) continue;

                    if (visited[ny][nx] == true) end_flag = true;

                    q.push({ny, nx});
                    visited_tmp[ny][nx] = true;
                    height_visited[ny][nx] = true;
                    cnt++;
                }
            }

            if (!end_flag) {
                sum += cnt;
            }
            else {
                for (int i=0; i<n; i++) {
                    for (int j=0; j<m; j++) {
                        if (visited_tmp[i][j] == true) {
                            visited[i][j] = true;
                        }
                    }
                }
            }
        }
    }

    cout << sum << endl;
}

