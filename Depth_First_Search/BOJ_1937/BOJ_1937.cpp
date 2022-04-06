#include <iostream>
#define MAX 500
using namespace std;

void fastio();
void input();
int dfs(int x, int y);
void solution();
void output();

int n, result;
int R[MAX][MAX];
int dp[MAX][MAX];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
    fastio();
    input();
    solution();
    output();
}

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> n;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            cin >> R[i][j];
        }
    }
}

int dfs(int x, int y){
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(R[nx][ny] > R[x][y]) dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }
    return dp[x][y];
}

void solution(){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            dfs(i, j);
            result = max(result, dp[i][j]);
        }
    }
}

void output(){
    cout << result;
}

