#include <iostream>
using namespace std;

int n, m, cnt = 0;
char graph[1002][1002];
int visit[1002][1002];

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char x;
			cin >> x;
			graph[i][j] = x;
		}
	}
}

void dfs(int x, int y, char direction)
{
	if (direction == 'U')
	{
		if (visit[x - 1][y] == 0)
		{
			visit[x - 1][y] = 1;
			dfs(x - 1, y, graph[x - 1][y]);
		}
		else if (visit[x - 1][y] == 1)
		{
			cnt++;
		}
	}
	else if (direction == 'D')
	{
		if (visit[x + 1][y] == 0)
		{
			visit[x + 1][y] = 1;
			dfs(x + 1, y, graph[x + 1][y]);
		}
		else if (visit[x + 1][y] == 1)
		{
			cnt++;
		}
	}
	else if (direction == 'L')
	{
		if (visit[x][y - 1] == 0)
		{
			visit[x][y - 1] = 1;
			dfs(x, y - 1, graph[x][y - 1]);
		}
		else if (visit[x][y - 1] == 1)
		{
			cnt++;
		}
	}
	else if (direction == 'R')
	{
		if (visit[x][y + 1] == 0)
		{
			visit[x][y + 1] = 1;
			dfs(x, y + 1, graph[x][y + 1]);
		}
		else if (visit[x][y + 1] == 1)
		{
			cnt++;
		}
	}
	visit[x][y] = 2;
}

void Solve()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (visit[i][j] == 0)
			{
				visit[i][j] = 1;
				dfs(i, j, graph[i][j]);
			}
		}
	}
}

void Print()
{
	cout << cnt;
}

int main()
{
	Input();
	Solve();
	Print();
}