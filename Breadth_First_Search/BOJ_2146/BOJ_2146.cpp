#include <bits/stdc++.h>
#define MAX 100
using namespace std;

void fastio();
void input();
void setLabel(int a, int b);
int bridgeLength(int num);
void solution();
void output();

int n, result = INT_MAX, label = 1;;
int R[MAX][MAX];
bool visited[MAX][MAX];

int d[4][2]= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int, int>> RQ;

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
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> R[i][j];
            if (R[i][j] == 1){
                RQ.push({i, j});
            }
        }
    }
}

void setLabel(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    R[a][b] = label;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n){
                if (!visited[nx][ny] && R[nx][ny] == 1){
                    visited[nx][ny] = true;
                    R[nx][ny] = label;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int bridgeLength(int num){
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (R[i][j] == num){
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()){
        int s = q.size();
        for (int i = 0; i < s; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++){
                int nx = x + d[j][0];
                int ny = y + d[j][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n){
                    if (R[nx][ny] != 0 && R[nx][ny] != num) return cnt;
                    else if (R[nx][ny] == 0 && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cnt++;
    }
    return -1;
}

void initialize(){
    while(!RQ.empty()){
        int x = RQ.front().first;
        int y = RQ.front().second;
        RQ.pop();
        if (!visited[x][y]){
            setLabel(x, y);
            label++;
        }
    }
}

void solution(){
    initialize();
    for (int i = 1; i < label; i++){
        memset(visited, false, sizeof(visited));
        result = min(result, bridgeLength(i));
    }
}

void output(){
    cout << result;
}



