#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<char>> m;
stack<pair<int, int>> xy;
int cnt = 0;
int R, C;
int cy[3] = {1, 0, -1};

void dfs(int x, int y) {

    m[y][x] = 'o';

    if (x == 0) {
        while (!xy.empty()) xy.pop();
        cnt++;
    }

    else {
        for (int i = 0; i < 3; i++) {
            if (y + cy[i] < R && y + cy[i] >= 0) {
                if (m[y + cy[i]][x - 1] == '.') {
                    xy.push({x, y});
                    dfs(x - 1, y + cy[i]);
                    break;
                }
            }

            if (i == 2) {
                m[y][x] = 'n';

                if (!xy.empty()) {
                    x = xy.top().first;
                    y = xy.top().second;
                    xy.pop();
                    dfs(x, y);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	m.assign(R, vector<char>(C));

	for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> m[i][j];
        }
    }

    for (int i = R - 1; i >= 0; i--) {
        dfs(C - 1, i);
    }

    cout << cnt;
}


