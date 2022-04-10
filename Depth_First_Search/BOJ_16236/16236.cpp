#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int AHang[20][20];
int road[20][20];
pair<int, int> at;
int now_size = 2;
int fish = 0;
int N, temp;
queue<pair<int, int>> go, te2;
vector<pair<int, int>> visit,te;
int sum;
bool check(pair<int, int> now) {
    if (now.first - 1 > -1 && road[now.first - 1][now.second] == 0) {
        temp = AHang[now.first - 1][now.second];
        if (temp < now_size && temp != 0) visit.push_back({ now.first - 1,now.second });
        else if (temp == now_size || temp == 0) go.push({ now.first - 1,now.second });
        road[now.first - 1][now.second] = 1;
    }
    if (now.second - 1 > -1 && road[now.first][now.second - 1] == 0) {
        temp = AHang[now.first][now.second - 1];
        if (temp < now_size && temp != 0) visit.push_back({ now.first,now.second - 1 });
        else if (temp == now_size || temp == 0) go.push({ now.first,now.second - 1 });
        road[now.first][now.second - 1] = 1;
    }
    if (now.second + 1 < N && road[now.first][now.second + 1] == 0) {
        temp = AHang[now.first][now.second + 1];
        if (temp < now_size && temp != 0) visit.push_back({ now.first,now.second + 1 });
        else if (temp == now_size || temp == 0) go.push({ now.first,now.second + 1 });
        road[now.first][now.second + 1] = 1;
    }
    if (now.first + 1 < N && road[now.first + 1][now.second] == 0) {
        temp = AHang[now.first + 1][now.second];
        if (temp < now_size && temp != 0) visit.push_back({ now.first + 1,now.second });
        else if (temp == now_size || temp == 0) go.push({ now.first + 1,now.second });
        road[now.first + 1][now.second] = 1;
    }
    if (visit.empty()) return false;
    else return true;

}

int dps(pair<int, int> now) {
    int gogo = 0;
    while (1) {
        while (1) {
            gogo = 1;
            visit = te;
            go = te2;
            road[now.first][now.second] = 1;
            AHang[now.first][now.second] = 0;
            check(now);
            while (visit.empty()) {
                int s = go.size();
                for (int i = 0; i < s; i++) {
                    check(go.front());
                    go.pop();
                }
                gogo++;
                if (go.empty() && visit.empty()) {return sum;}
            }
            sort(visit.begin(), visit.end());
            sum += gogo;
            now = visit.front();
            fish++;
            if (fish == now_size) { now_size++; fish = 0; }
            memset(road, 0, sizeof(road));
        }   
    }
}


int solution() {
    cout<< dps(at);
    return 0;
}


int main(void) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> AHang[i][j];
                if (AHang[i][j] == 9) {
                    at.first = i;
                    at.second = j;
                    road[i][j] = 1;
                }
            }
        }
        solution();
}
