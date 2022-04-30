#include <iostream>
using namespace std;

int height[500];

int main() {
	int v, h;
	cin >> v >> h;

	int res = 0;
	
	for (int i = 0; i < h; i++) {
		cin >> height[i];
	}

	for (int i = 1; i < h-1; i++) {   // 양끝은 고려 대상 X (벽)
		int L = 0, R = 0;

		for (int left = 0; left < i; left++) {
			L = max(L, height[left]);
		}
		for (int right = i + 1; right < h; right++) {
			R = max(R, height[right]);
		}

		int tmp = min(L, R) - height[i];
		if (tmp > 0) res += tmp;
	}

	cout << res; 

	return 0;
}
