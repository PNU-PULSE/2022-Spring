#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int k, n, result;
vector <long long> Num;
map <long long, bool> visit;

void Input()
{
	cin >> k >> n;
	while (k--)
	{
		long long x;
		cin >> x;
		Num.push_back(x);
	}
}

void Solve()
{
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	pq.push(1);
	visit[1] = true;

	long long MaxValue = 0;

	while (n--)
	{
		long long now = pq.top();
		pq.pop();
		for (auto i : Num)
		{
			if (visit.count(now*i)) continue;
			if (pq.size() > n)
			{
				if (now * i >= MaxValue) continue;
			}
			pq.push(now * i);
			MaxValue = max(MaxValue, now * i);
			visit[now * i] = true;
		}
	}

	result = pq.top();
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