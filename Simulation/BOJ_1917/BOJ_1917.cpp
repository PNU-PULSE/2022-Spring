#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int dev[6][6] = {0};

int a_x[4] = {-1, 0, 0, 1};
int a_y[4] = {0, -1, 1, 0};

int b_x[4] = {-2, -2, 2, 2};
int b_y[4] = {-2, 2, -2, 2};

int dev_three_cnt() {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (dev[i][j] == 3) cnt++;
        }
	}
	return cnt;
}

void fun_assign() {
	for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dev[i][j];
            if (dev[i][j] == 1) q.push({i, j});
        }
	}
}

bool is_valid(int x, int y, int a, int b) {
    if (a > x) swap(x, a);
    if (b > y) swap(y, b);

    if (x - a == 2 && y - b == 2) {
        bool ta = 0, tb = 0;
        for (int i = b; i <= y; i++) {
            if (dev[(a + x) / 2][i] == 0) ta = 1;
        }
        for (int i = a; i <= x; i++) {
            if (dev[i][(y + b) / 2] == 0) tb = 1;
        }

        if (ta && tb) return 0;
    }
    else if (x - a == 2) {
        for (int i = b; i <= y; i++) {
            if (dev[(a + x) / 2][i] == 0) return 0;
        }
    }
    else if (y - b == 2) {
        for (int i = a; i <= x; i++) {
            if (dev[i][(y + b) / 2] == 0) return 0;
        }
    }

    return 1;
}

void is_cube() {
    int x, y;

    fun_assign();

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (x + (a_x[i] * 2) >= 0 && x + (a_x[i] * 2) < 6 && y + (a_y[i] * 2) >= 0 && y + (a_y[i] * 2) < 6) {
                if (dev[x + (a_x[i] * 2)][y + (a_y[i] * 2)] > 0) {
                    if (is_valid(x, y, x + (a_x[i] * 2), y + (a_y[i] * 2))) {
                        dev[x][y]++;
                        dev[x + (a_x[i] * 2)][y + (a_y[i] * 2)]++;
                    }
                }
            }

            if (x + b_x[i] >= 0 && x + b_x[i] < 6 && y + b_y[i] >= 0 && y + b_y[i] < 6) {
                if (dev[x + b_x[i]][y + b_y[i]] > 0) {
                    if (is_valid(x, y, x + b_x[i], y + b_y[i])) {
                        dev[x][y]++;
                        dev[x + b_x[i]][y + b_y[i]]++;
                    }
                }
            }

            for (int j = 0; j < 4; j++) {
                if (x + b_x[i] + a_x[j] >= 0 && x + b_x[i] + a_x[j] < 6 && y + b_y[i] + a_y[j] >= 0 && y + b_y[i] + a_y[j] < 6) {
                    if (dev[x + b_x[i] + a_x[j]][y + b_y[i] + a_y[j]] > 0) {
                        if (is_valid(x, y, x + b_x[i] + a_x[j], y + b_y[i] + a_y[j])) {
                            dev[x][y]++;
                            dev[x + b_x[i] + a_x[j]][y + b_y[i] + a_y[j]]++;
                        }
                    }
                }
            }
        }
    }

    if (dev_three_cnt() == 6) cout << "yes\n";
    else cout << "no\n";
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    for (int i = 0; i < 3; i++) is_cube();
}

