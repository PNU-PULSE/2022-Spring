#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, result = 0;
vector<int> Nums;
vector<int> Diff;

void Input()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		Nums.push_back(x);
	}
}

void Solve()
{
	for (int i = 0; i < n - 1; i++) Diff.push_back(Nums[i + 1] - Nums[i]);
	sort(Diff.begin(), Diff.end());
	for (int i = 0; i < n - k; i++) result += Diff[i];
}

void Print()
{
	cout << result;
}

int main()
{
	Input();
	Solve();
	Print();
}