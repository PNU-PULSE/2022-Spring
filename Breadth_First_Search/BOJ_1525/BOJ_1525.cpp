#include <iostream>
#include <queue>
#include <set>

using namespace std;

int next_idx[9][4]{ // next_step {up, down, left, right}
	{-1, 3, -1, 1},
	{-1, 4, 0, 2},
	{-1, 5, 1, -1},
	{0, 6, -1, 4},
	{1, 7, 3, 5},
	{2, 8, 4, -1},
	{3, -1, -1, 7},
	{4, -1, 6, 8 },
	{5, -1, 7, -1}
};


void BFS(string str, int idx) {
	
	queue<string> q;
	set<string> visited;
	string target{ "123456780" };
	if (str == target) {
		cout << 0;
		return;
	}
	int res = 987654321;
	int step = 1;

	q.push(str);
	visited.insert(str);

	while (!q.empty()) {
		int curr_size = q.size();
		int zero_idx;
		string front;
		for (int _ = 0; _ < curr_size; ++_) {
			front = q.front();
			q.pop();
			for (zero_idx = 0; front[zero_idx] != '0'; ++zero_idx); // front 절대 안 벗어남
			for (int i = 0; i < 4; ++i) {
				int next = next_idx[zero_idx][i];
				if (next == -1) {
					continue;
				}
				string next_str{ front };
				swap(next_str[zero_idx], next_str[next]);
				if (next_str == target) {
					cout << step;
					return;
				}
				else if (visited.find(next_str) == visited.end()) {
					visited.insert(next_str);
					q.push(next_str);
				}
			}
		}
		++step;
	}

	cout << -1;
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string puzzle;
	int zero_idx;
	for (int i = 0, num; i < 9; ++i) {
		cin >> num;
		puzzle += char(num + '0');
		if (num == 0) {
			zero_idx = i;
		}
	}

	BFS(puzzle, zero_idx);

	return 0;
}