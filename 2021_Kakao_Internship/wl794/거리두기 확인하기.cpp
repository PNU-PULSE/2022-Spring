#include <string>
#include <vector>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int curY, curX;

bool DFS(vector<string> v, int y, int x, int dist) {
    if (v[y][x] == 'P' && !(curY == y && curX == x)) return true;
    if (dist == 2) return false;

    bool ans = false;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
        if (v[ny][nx] == 'X') continue;
        ans = ans || DFS(v, ny, nx, dist + 1);
    }
    return ans;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (vector<string> v: places) {
        bool ans = true;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (v[i][j] == 'P') {
                    curY = i;
                    curX = j;
                    if (DFS(v, i, j, 0) == true) {
                        ans = false;
                        break;
                    }
                }
            }
            if (ans == false) break;
        }

        if (ans == false) answer.push_back(0);
        else answer.push_back(1);
    }

    return answer;
}
