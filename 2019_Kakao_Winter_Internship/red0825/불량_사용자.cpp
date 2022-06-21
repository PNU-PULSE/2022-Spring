#include <string>
#include <vector>

using namespace std;

bool visited[1 << 8];

bool cmp(string a, string b){
    if(a.length() != b.length()) return false;
    for(int i = 0; i < a.length(); i++){
        if(b[i] == '*') continue;
        if(a[i] != b[i]) return false;
    }
    return true;
}

void dfs(int cnt, int n, int bits, vector<vector<int>> &R){
    if(cnt == n){
        visited[bits] = true;
        return;
    }
    for(auto x : R[cnt]){
        if(bits&(1<<x)) continue;
        dfs(cnt + 1, n, bits|(1<<x), R);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> R(banned_id.size());
    for(int i = 0; i < banned_id.size(); i++){
        for(int j = 0; j < user_id.size(); j++){
            if(cmp(user_id[j], banned_id[i])){
                R[i].push_back(j);
            }
        }
    }
    dfs(0, banned_id.size(), 0, R);
    for(int i = 0; i < (1 << 8); i++){
        if(visited[i]) answer++;
    }
    return answer;
}
