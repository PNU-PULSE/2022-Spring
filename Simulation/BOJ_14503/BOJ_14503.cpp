#include <iostream>
using namespace std;

int v, h;
int r, c, d;
int map[50][50];
int cleaned[50][50];

int dv[4] = { -1, 0, 1, 0 };
int dh[4] = { 0, 1, 0, -1 };


void dfs(int& cnt, int cv, int ch, int cd);

int main() {
	cin >> v >> h;
	cin >> r >> c >> d;

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < h; j++) {
			cin >> map[i][j];
			cleaned[i][j] = map[i][j];
		}
	}

	int count = 0; 

	dfs(count, r, c, d);

	return 0;
}

void dfs(int& cnt, int cv, int ch, int cd) {	
	if (cleaned[cv][ch] == 0) {
		cleaned[cv][ch] = 1;
		cnt++;
	}

	for (int i = 0; i < 4; i++) {
		int nd = (cd + 3 - i) % 4;
		int nv = cv + dv[nd];
		int nh = ch + dh[nd];

		if (nv < 0 || nv >= v || nh < 0 || nh >= h) continue;

		if (map[nv][nh] == 1 || cleaned[nv][nh] == 1) { 
			continue;
		}
		dfs(cnt, nv, nh, nd);
	}
	
	int rd = (cd + 2) % 4;
	int rv = cv + dv[rd];
	int rh = ch + dh[rd];

	if (rv >= 0 && rv < v && rh >= 0 && rh < h) {
		if (map[rv][rh] == 1) {
			cout << cnt;
			exit(0);
		}
		else {
			dfs(cnt, rv, rh, cd);
		}
	}
}
