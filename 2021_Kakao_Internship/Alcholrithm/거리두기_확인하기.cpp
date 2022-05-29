#include <vector>
#include <string>

using namespace std;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

bool flag;

void dfs(vector<string>& vec, int x, int y, int t_x, int t_y, int cnt) {
    if (cnt == 2) {
        return;
    }
    for(int i =0 ; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=0 && nx < 5 && ny >= 0 && ny < 6 && vec[nx][ny] != 'X') {
            if (nx == t_x && ny == t_y) {
                continue;
            }
            if(vec[nx][ny] == 'P') {
                flag = false;
                return;
            }
            dfs(vec, nx, ny, t_x, t_y, cnt + 1);
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto p : places) {
        bool sol_flag = true;
        for(int i = 0; i< 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (p[i][j] == 'P') {
                    flag = true;
                    dfs(p, i, j, i, j, 0);
                    if (!flag) {
                        sol_flag = false;
                    }
                }
            }
        }
        if (sol_flag) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }
    return answer;
}