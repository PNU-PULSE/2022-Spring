#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[]{ 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[]{ 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int next_dir[]{ 0, 2, 3, 4, 5, 6, 7, 8, 1 };

using pii = pair<int, int>;

int res = -1;

pii coordi[17]; // y , x
bool comp(int a, int b) {
	return a > b; 
}


void dfs(vector<vector<pii>> space, int y, int x, int summation) {
	priority_queue <int, vector<int>, decltype(&comp)> pq(comp);
	space[y][x].first = -1;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (space[i][j].first > 0) {
				pq.push(space[i][j].first);
				coordi[space[i][j].first] = { i, j };
			}
		}
	}

	while (!pq.empty()) {
		int top = pq.top();
		int dir = space[coordi[top].first][coordi[top].second].second;
		int nx = coordi[top].second + dx[dir];
		int ny = coordi[top].first + dy[dir];

		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && space[ny][nx].first != -1) {
			pii n = space[ny][nx];
			swap(space[coordi[top].first][coordi[top].second], space[ny][nx]);
			swap(coordi[top], coordi[n.first]);
			pq.pop();
		}
		else {
			space[coordi[top].first][coordi[top].second].second = next_dir[space[coordi[top].first][coordi[top].second].second];
		}
	}

	int m = 1;
	while (true) {
		int nx = x + dx[space[y][x].second] * m;
		int ny = y + dy[space[y][x].second] * m;
		if (nx < 0 || nx > 3 || ny < 0 || ny > 3) {
			break;
		}
		auto temp = space;

		if (space[ny][nx].first > 0) {
			int next_summation = summation + space[ny][nx].first;
			res = max(res, next_summation);
			temp[y][x].first = 0;
			dfs(temp, ny, nx, next_summation);
		}
		++m;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<pii>> space(4, vector<pii>(4));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> space[i][j].first >> space[i][j].second;
		}
	}


	dfs(space, 0, 0, space[0][0].first);
	cout << res;

	return 0;
}