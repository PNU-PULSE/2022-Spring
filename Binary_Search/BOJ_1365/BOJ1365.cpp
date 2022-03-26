#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
	cin >> n;
	
	vector<int> input;
	vector<int> LIS;


	for (int i = 0; i < n; i++) {
		int tmp;	cin >> tmp;
		input.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			LIS.push_back(input[i]);
		}
		else {
			if (input[i] > LIS.back()) {
				LIS.push_back(input[i]);
			}else {
				vector<int>::iterator iter 
					= lower_bound(LIS.begin(), LIS.end(), input[i]);
				*iter = input[i];
			}
		}
	}

	cout << n - LIS.size();
	

	return 0;
}
