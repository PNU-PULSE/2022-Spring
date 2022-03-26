#include <iostream>
using namespace std;

int n;
long long int arr[100001];
long long int Liquid1, Liquid2;

void Print()
{
	cout << Liquid1 << " " << Liquid2;
}

void Solve()
{
	int left = 0, right = n - 1;
	Liquid1 = arr[left];
	Liquid2 = arr[right];
	int SumLiquid = abs(Liquid1 + Liquid2);

	while (left < right)
	{
		int temp = arr[left] + arr[right];
		if (SumLiquid > abs(temp))
		{
			SumLiquid = abs(temp);
			Liquid1 = arr[left];
			Liquid2 = arr[right];
		}

		if (temp > 0) right--;
		else left++;
	}
}

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
}

int main()
{
	Input();
	Solve();
	Print();
}