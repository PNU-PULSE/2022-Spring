#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
int result = -1;
vector<int> graph;

void Input()
{
	cin >> n >> c;
	while (n--)
	{
		int x;
		cin >> x;
		graph.push_back(x);
	}
}

void BinarySearch(int low, int high)
{
	if (low > high) return;

	int mid = (low + high) / 2;
	int count = 1;
	int value = graph[0];

	for (int i = 1; i < graph.size(); i++)
	{
		if (graph[i] >= value + mid)
		{
			value = graph[i];
			count++;
		}
	}

	if (count >= c)
	{
		result = mid;
		BinarySearch(mid + 1, high);
	}
	else BinarySearch(low, mid - 1);
}

void Solve()
{
	sort(graph.begin(), graph.end());
	BinarySearch(1, graph.back());
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