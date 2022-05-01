#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int arr[20][20];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int vert[4] = {4, 1, 3, 6};
int hori[4] = {2, 1, 5, 6};

/*
  2
4 1 3 6
  5
  6
*/

int next(int a) { return (a+1 != 4) ? a+1 : 0; }
int prev(int a) { return (a-1 != -1) ? a-1 : 3; }

int BFS(int y, int x, int value) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    int cnt = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        cnt++;

        for (int i=0; i<4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] != value) continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    return cnt;
}

void move_right() {
    int tmp = vert[3];
    vert[3] = vert[2];
    vert[2] = vert[1];
    vert[1] = vert[0];
    vert[0] = tmp;
    hori[1] = vert[1];
    hori[3] = 7 - vert[1];
}

void move_left() {
    int tmp = vert[0];
    vert[0] = vert[1];
    vert[1] = vert[2];
    vert[2] = vert[3];
    vert[3] = tmp;
    hori[1] = vert[1];
    hori[3] = 7 - vert[1];
}

void move_up() {
    int tmp = hori[0];
    hori[0] = hori[1];
    hori[1] = hori[2];
    hori[2] = hori[3];
    hori[3] = tmp;
    vert[1] = hori[1];
    vert[3] = 7 - hori[1];
}

void move_down() {
    int tmp = hori[3];
    hori[3] = hori[2];
    hori[2] = hori[1];
    hori[1] = hori[0];
    hori[0] = tmp;
    vert[1] = hori[1];
    vert[3] = 7 - hori[1];
}

int dice_num() { return hori[3]; }

int main() {
    cin >> n >> m >> k;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> arr[i][j];


    int x = 0;
    int y = 0;
    int dir = 0;

    int sum = 0;
    while (k--) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            dir = next(next(dir));
            k++;
            continue;
        }

        x = nx;
        y = ny;

        sum += BFS(y, x, arr[y][x]) * arr[y][x];

        if (dir == 0) move_right();
        else if (dir == 1) move_down();
        else if (dir == 2) move_left();
        else if (dir == 3) move_up();

        if (dice_num() > arr[ny][nx]) dir = next(dir);
        else if (dice_num() < arr[ny][nx]) dir = prev(dir);
    }

    cout << sum << endl;
}
