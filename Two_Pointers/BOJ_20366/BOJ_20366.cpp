#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

int n;
vector<int> vec;
int res = 1e9;

void solve(void) {
	int height;
	int gap;
	for (int i = n - 1; i >= 3; --i) {
		for (int j = 0; j < i - 1; ++j) {
			height = vec[i] + vec[j];
			for (int k = i - 1, l; k > j; --k) { // k가 j보다 작아지면 의미 x
				int target = height - vec[k];
				l = lower_bound(&vec[0], &vec[k], target) - &vec[0]; // vec[k] + vec[l] > height
				for (int idx = l - 4; idx <= l + 4; idx++) {
					if (idx < 0 || idx >= n || idx == i || idx == j || idx == k) {
						continue;
					}
					res = min(res, abs(target - vec[idx]));
				}
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vec.resize(n);

	for (auto& v : vec) {
		cin >> v;
	}

	sort(vec.begin(), vec.end());
	solve();

	cout << res;
	return 0;
}