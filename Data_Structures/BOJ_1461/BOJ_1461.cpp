#include <iostream>
#include <algorithm>
using namespace std;

int loc[50];

int main() {
	int n, m;
	cin >> n >> m;

	int negative = 0;

	for (int i = 0; i < n; i++){
		cin >> loc[i];
		if (loc[i] < 0) negative++;
	}

	sort(loc, loc + n);

	int cost = 0;

	if (abs(loc[0]) > abs(loc[n - 1])) {
		cost -= abs(loc[0]);
	}
	else {
		cost -= abs(loc[n - 1]);
	}

	for (int i = 0; i < negative; i += m) {
		cost += abs(loc[i])*2;
	}
	for (int i = n-1; i >= negative; i -= m) {
		cost += abs(loc[i]) * 2;
	}

	cout << cost;

	return 0;
}

