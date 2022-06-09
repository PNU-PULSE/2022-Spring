#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<string>> res;

bool check(string id, string banned){
    if(id.length()!=banned.length())
        return false;
    size_t i;
    for(i = 0; i<id.length() && (banned[i]=='*' || id[i]==banned[i]);++i);
    if(i == id.length())
        return true;
    return false;
}
int make_set(){
    set<vector<string>> result;
    for(auto vstr : res){
        result.emplace(vstr);
    }
    return result.size();
}
void find(vector<string> user_id, vector<string> banned_id, size_t ui, size_t bi, vector<string> tt){
    if (bi == banned_id.size())
        res.push_back(tt);
    else if(ui == user_id.size())
        return;
    else if(check(user_id[ui],banned_id[bi])){
        vector<string> tt2{tt};
        tt.push_back(user_id[ui]);
        find(user_id, banned_id, ui + 1, bi + 1, tt);
        find(user_id, banned_id, ui + 1, bi, tt2);
    }
    else
        find(user_id, banned_id, ui + 1, bi, tt);
}

int solution(vector<string> user_id, vector<string> banned_id) {
    sort(banned_id.begin(),banned_id.end());
    do{
        find(user_id, banned_id, 0, 0, vector<string>());
    } while(next_permutation(banned_id.begin(), banned_id.end()));
    int answer = make_set();
    return answer;
}