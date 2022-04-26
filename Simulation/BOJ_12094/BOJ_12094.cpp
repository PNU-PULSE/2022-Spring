#include <iostream>

using namespace std;

int maximum = -987654321;

struct Game {
	int N;
	int board[20][20];
	int curr_max = -987654321;
	bool is_changed = true;
	bool is_merged;

	void move_top(void) {
		for (int j = 0; j < this->N; ++j) {
			this->is_merged = false;
			int idx = 0;
			for (int i = 0; i < this->N; ++i) {
				if (this->board[i][j]) {
					this->board[idx][j] = this->board[i][j];
					if (idx != i) {
						this->board[i][j] = 0;
						this->is_changed = true;
					}
					if (idx != 0 && (this->board[idx][j]) == (this->board[idx - 1][j]) && !is_merged) {
						is_merged = true;
						this->board[idx - 1][j] *= 2;
						this->board[idx][j] = 0;
						this->is_changed = true;
					}
					else {
						++idx;
						is_merged = false;
					}
				}
				else if (this->board[idx][j]) {
					idx = i;
					this->is_changed = true;
				}
			}
		}
	}

	void move_bottom(void) {
		for (int j = 0; j < this->N; ++j) {
			this->is_merged = false;
			int idx = this->N - 1;
			for (int i = this->N - 1; i >= 0; --i) {
				if (this->board[i][j]) {
					this->board[idx][j] = this->board[i][j];
					if (idx != i) {
						this->board[i][j] = 0;
						this->is_changed = true;
					}
					if (idx != N - 1 && (this->board[idx][j]) == (this->board[idx + 1][j]) && !is_merged) {
						is_merged = true;
						this->board[idx + 1][j] *= 2;
						this->board[idx][j] = 0;
						this->is_changed = true;
					}
					else {
						--idx;
						is_merged = false;
					}
				}
				else if (this->board[idx][j]) {
					idx = i;
					this->is_changed = true;
				}
			}
		}
	}

	void move_left(void) {
		for (int i = 0; i < this->N; ++i) {
			this->is_merged = false;
			int idx = 0;
			for (int j = 0; j < this->N; ++j) {
				if (this->board[i][j]) {

					this->board[i][idx] = this->board[i][j];
					if (idx != j) {
						this->board[i][j] = 0;
						this->is_changed = true;
					}
					if (idx != 0 && (this->board[i][idx]) == (this->board[i][idx - 1]) && !is_merged) {
						is_merged = true;
						this->board[i][idx - 1] *= 2;
						this->board[i][idx] = 0;
						this->is_changed = true;
					}
					else {
						++idx;
						is_merged = false;
					}
				}
				else if (this->board[i][idx]) {
					idx = j;
					this->is_changed = true;
				}
			}
		}
	}

	void move_right(void) {
		for (int i = 0; i < this->N; ++i) {
			this->is_merged = false;
			int idx = this->N - 1;
			for (int j = this->N - 1; j >= 0; --j) {
				if (this->board[i][j]) {

					this->board[i][idx] = this->board[i][j];
					if (idx != j) {
						this->board[i][j] = 0;
						this->is_changed = true;
					}
					if (idx != N - 1 && (this->board[i][idx]) == (this->board[i][idx + 1]) && !is_merged) {
						is_merged = true;
						this->board[i][idx + 1] *= 2;
						this->board[i][idx] = 0;
						this->is_changed = true;
					}
					else {
						--idx;
						is_merged = false;
					}
				}
				else if (this->board[i][idx]) {
					idx = j;
					this->is_changed = true;
				}
			}
		}
	}
};

void move_board(Game& game, int op) {
	switch (op) {
	case 0:
		game.move_top();
		break;
	case 1:
		game.move_bottom();
		break;
	case 2:
		game.move_left();
		break;
	case 3:
		game.move_right();
		break;
	}
}

void solve(Game game, int depth, int op) {
	if (depth == 10) {
		return;
	}

	game.is_changed = false;
	move_board(game, op);
	for (int i = 0; i < game.N; ++i) {
		for (int j = 0; j < game.N; ++j) {
			game.curr_max = max(game.curr_max, game.board[i][j]);
		}
	}
	if (!game.is_changed || game.curr_max * (10 - depth) <= maximum) {
		return;
	}

	maximum = max(maximum, game.curr_max);

	for (int o = 0; o < 4; ++o) {
		solve(game, depth + 1, o);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Game game;
	cin >> game.N;

	for (int i = 0; i < game.N; ++i) {
		for (int j = 0; j < game.N; ++j) {
			cin >> game.board[i][j];
			maximum = max(maximum, game.board[i][j]);
		}
	}

	for (int o = 0; o < 4; ++o) {
		solve(game, 0, o);
	}

	cout << maximum;
	return 0;
}