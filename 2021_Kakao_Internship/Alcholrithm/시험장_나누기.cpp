#include <vector>

using namespace std;

vector<int> adj[10101];
bool check[10101];
int root;
bool flag;
int cnt{};

int dfs(vector<int>& num, int u, int m) {
    if (num[u] >m) {
        flag = false;
    }
    int k1, k2;
    if (adj[u].size() == 2) {
        k1 = dfs(num, adj[u][0], m);
        k2 = dfs(num, adj[u][1], m);
        if (k1 + k2 + num[u] <= m) {
            return k1 + k2 + num[u];
        }
        else {
            if (k1 + num[u] > m && k2 + num[u] > m) {
                cnt += 2;
                return num[u];
            }
            else if (k1 + num[u] > m) {
                ++cnt;
                return k2 + num[u];
            }
            else if (k2 + num[u] > m) {
                ++cnt;
                return k1 + num[u];
            }
            else {
                if (k1 > k2) {
                    ++cnt;
                    return k2 + num[u];
                }
                else {
                    ++cnt;
                    return k1 + num[u];
                }
            }
        }
    }
    else if (adj[u].size() == 1) {
        k1 = dfs(num, adj[u][0], m);
        if (k1 + num[u] > m) {
            ++cnt;
            return num[u];
        }
        else {
            return k1 + num[u];
        }
    }
    else {
        return num[u];
    }
}

bool search(vector<int>& num, int k, int m) {
    cnt = 0;
    flag = true;
    dfs(num, root, m);
    if (cnt >= k || ! flag) {
        return false;
    }
    return true;
}
int solution (int k, vector<int> num, vector<vector<int>> links) {
    int answer = 987654321;
    for(int i = 0; i < links.size(); ++i) {
        if (links[i][0] != -1) {
            adj[i].push_back(links[i][0]);
            check[links[i][0]] = true;
        }
        if (links[i][1] != -1) {
            adj[i].push_back(links[i][1]);
            check[links[i][1]] = true;
        }
    }
    for(int i = 0; i< num.size(); ++i) {
        if (!check[i]) {
            root = i;
        }
    }
    int start = 1;
    int end = 1e8;
    while(start <= end) {
        int mid = (start + end) / 2;
        if (search(num, k, mid)) {
            answer = min(answer, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return answer;
}