#include <iostream>
using namespace std;

int h, w, result = 0;
int lst[501];

void Print()
{
	cout << result;
}

void Solve()
{
	for (int i = 1; i < w-1; i++)
	{
		int left = 0, right = 0;
		for (int j = 0; j < i; j++) left = max(left, lst[j]);
		for (int j = w - 1; j > i; j--) right = max(right, lst[j]);
		result += max(0, min(left, right) - lst[i]);
	}
}

void Input()
{
	cin >> h >> w;
	for (int i = 0; i < w; i++)
	{
		cin >> lst[i];
	}
}

int main()
{
	Input();
	Solve();
	Print();
}