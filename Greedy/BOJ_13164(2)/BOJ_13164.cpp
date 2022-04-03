#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

long long height[300000];
long long dif[300000];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	for (int i = 0; i < n-1; i++) {
		dif[i] = height[i + 1] - height[i];
	}

	sort(dif, dif + n - 1);

	long long result = 0;
	result = accumulate(dif, dif + n -k, result);
	
	cout << result;
	
	return 0;
}
