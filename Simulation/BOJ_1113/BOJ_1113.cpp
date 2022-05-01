#include <iostream>
#include <queue>
#define MAX 52
using namespace std;

void fastio();
void input();
void bfs();
void solution();
void output();

int n, m, maxVal = 0;
int R[MAX][MAX];
int d[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int result;

int main(){
    input();
    solution();
    output();
}

void input(){
    scanf(" %d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf(" %1d", &R[i][j]);
            if(R[i][j] > maxVal) maxVal = R[i][j];
        }
    }
}

void bfs(int pos){
    queue<pair<int ,int>> q;
    R[0][0] = pos;
    q.push({0, 0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1 || R[nx][ny] >= pos) continue;
            R[nx][ny] = pos;
            q.push({nx, ny});
        }

    }
}

void solution(){
    for(int k = 1; k <= maxVal; k++){
        bfs(k);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(R[i][j] < k){
                    result++;
                    R[i][j]++;
                }
            }
        }
    }
}

void output(){
    cout << result;
}

