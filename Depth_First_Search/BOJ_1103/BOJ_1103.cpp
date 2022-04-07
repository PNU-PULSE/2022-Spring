#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
char board[50][50];
bool visited[50][50];
int dp[50][50];

int dx[]{ -1, 1, 0, 0 };
int dy[]{ 0, 0, -1, 1 };

constexpr int INF{ 987654321 };


int DFS(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N || board[y][x] == 'H') {
		return 0;
	}
	if (visited[y][x]) {
		return INF;
	}

	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	int curr = board[y][x] - '0';
	visited[y][x] = true;
	dp[y][x] = 0;

	for (int i = 0; i < 4; ++i) {
		dp[y][x] = max(dp[y][x], DFS(x + dx[i] * curr, y + dy[i] * curr) + 1);
	}
	visited[y][x] = false;

	return dp[y][x];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));

	int res = DFS(0, 0);

	if (res < INF) {
		cout << res;
	}
	else {
		cout << -1;
	}

	return 0;
}