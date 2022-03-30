#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

bool visited[4][4] = { false, };
string boggle[4];

int dx[]{ -1,-1, -1, 0, 0, 1, 1, 1 };
int dy[]{ -1, 1, 0, -1, 1, 0, -1, 1};

unordered_set<string> res; // 중복을 막기 위해
int score[9]{ 0,0,0,1,1,2,3,5,11 };

struct Trie {

	Trie* next[26];
	bool is_end;

	Trie() {
		memset(this->next, 0, sizeof(this->next));
		is_end = false;
	}
	void search(int x, int y, string str) {
		if (str.length() > 8) { // 단어는 8글자 이하
			return;
		}
		visited[y][x] = true;
		str += boggle[y][x];

		auto curr = this->next[boggle[y][x] - 'A'];
		if (curr == nullptr) { // 트라이에 없는 단어
			visited[y][x] = false;
			return;
		}

		if (curr->is_end) { // 찾은 단어
			res.insert(str);
		}

		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !visited[ny][nx]) {
				curr->search(nx, ny, str);
			}
		}
		visited[y][x] = false;
	}
};



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int w;
	cin >> w;

	Trie* root = new Trie();
	Trie* node;

	string str;
	int idx;
	for (int i = 0; i < w; ++i) {
		cin >> str;
		idx = str[0] - 'A';
		node = root;
		for (auto c : str) {
			idx = c - 'A';
			if (node->next[idx] == nullptr) {
				node->next[idx] = new Trie();
			}
			node = node->next[idx];
		}
		node->is_end = true;
	}

	int b;
	cin >> b;

	int max_score;
	string longest_str;

	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> boggle[j];
		}
		res.clear();
		max_score = 0;
		longest_str.clear();
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				root -> search(j, k, "");
			}
		}
		for (auto s : res) {
			if (s.length() > longest_str.length()) {
				longest_str = s;
			}
			if (s.length() == longest_str.length() && s < longest_str) {
				longest_str = s;
			}
			max_score += score[s.length()];
		}
		cout << max_score << ' ' << longest_str << ' ' << res.size() << '\n';
	}


	return 0;
}