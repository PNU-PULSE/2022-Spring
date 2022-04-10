#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m, k, result;
int graph[1000][1000];
bool visit[11][1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

typedef struct Q
{
	int a, b, c, d, e;
}Q;

queue <Q> moved;

void Input()
{
	cin >> n >> m >> k;
	string st;
	for (int i = 0; i < n; i++)
	{
		cin >> st;
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = st[j] - '0';
		}
	}
}

void Solve()
{
	moved.push({ 0,0,0,1,1 });
	visit[0][0][0] = true;

	while (!moved.empty())
	{
		int x = moved.front().a;
		int y = moved.front().b;
		int k_count = moved.front().c;
		int distance = moved.front().d;
		int flag = moved.front().e;
		moved.pop();

		if (x == n - 1 and y == m - 1)
		{
			result = distance;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 and yy >= 0 and xx < n and yy < m)
			{
				if (graph[xx][yy] == 0)
				{
					if(visit[k_count][xx][yy] == false)
					{
						visit[k_count][xx][yy] = true;
						moved.push({ xx,yy,k_count,distance + 1,1 - flag });
					}
				}
				else
				{
					if (k_count < k)
					{
						if (visit[k_count + 1][xx][yy] == false)
						{
							if (flag)
							{
								visit[k_count + 1][xx][yy] = true;
								moved.push({ xx,yy,k_count + 1,distance + 1,1 - flag });
							}
							else
							{
								moved.push({ x,y,k_count,distance + 1,1 - flag });
							}
						}
					}
				}
			}
		}
	}
	result = -1;
}

void Print()
{
	cout << result << endl;
}

int main()
{
	Input();
	Solve();
	Print();
}