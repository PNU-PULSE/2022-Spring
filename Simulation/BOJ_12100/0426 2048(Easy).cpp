#include <iostream>
#include <queue>
using namespace std;

int n, result;
int graph[21][21];

void move_graph(int direction)
{
	queue<int> q;

	// 왼쪽
	if (direction == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j]) q.push(graph[i][j]);
				graph[i][j] = 0;
			}
			int idx = 0;

			while (!q.empty())
			{
				int data = q.front();
				q.pop();

				if (graph[i][idx] == 0)
				{
					graph[i][idx] = data;
				}
				else if (graph[i][idx] == data)
				{
					graph[i][idx] *= 2;
					idx++;
				}
				else
				{
					idx++;
					graph[i][idx] = data;
				}
			}
		}
	}
	// 오른쪽
	else if (direction == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n-1; j >= 0; j--)
			{
				if (graph[i][j]) q.push(graph[i][j]);
				graph[i][j] = 0;
			}
			int idx = n-1;

			while (!q.empty())
			{
				int data = q.front();
				q.pop();

				if (graph[i][idx] == 0)
				{
					graph[i][idx] = data;
				}
				else if (graph[i][idx] == data)
				{
					graph[i][idx] *= 2;
					idx--;
				}
				else
				{
					idx--;
					graph[i][idx] = data;
				}
			}
		}
	}
	// 위쪽
	else if (direction == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[j][i]) q.push(graph[j][i]);
				graph[j][i] = 0;
			}
			int idx = 0;

			while (!q.empty())
			{
				int data = q.front();
				q.pop();

				if (graph[idx][i] == 0)
				{
					graph[idx][i] = data;
				}
				else if (graph[idx][i] == data)
				{
					graph[idx][i] *= 2;
					idx++;
				}
				else
				{
					idx++;
					graph[idx][i] = data;
				}
			}
		}
	}
	// 아래쪽
	else if (direction == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n-1; j >= 0; j--)
			{
				if (graph[j][i]) q.push(graph[j][i]);
				graph[j][i] = 0;
			}
			int idx = n-1;

			while (!q.empty())
			{
				int data = q.front();
				q.pop();

				if (graph[idx][i] == 0)
				{
					graph[idx][i] = data;
				}
				else if (graph[idx][i] == data)
				{
					graph[idx][i] *= 2;
					idx--;
				}
				else
				{
					idx--;
					graph[idx][i] = data;
				}
			}
		}
	}
}

void dfs(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				result = max(result, graph[i][j]);
			}
		}
		return;
	}

	int graph2[21][21];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph2[i][j] = graph[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		move_graph(i);
		dfs(cnt + 1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				graph[i][j] = graph2[i][j];
			}
		}
	}
}



void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}
}

void Solve()
{
	dfs(0);
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