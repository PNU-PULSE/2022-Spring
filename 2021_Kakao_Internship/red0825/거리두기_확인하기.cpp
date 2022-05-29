#include <string>
#include <vector>

using namespace std;

int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int check(vector<string> s){
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s[i].length(); j++){
            if(s[i][j] == 'P'){
                for(int k = 0; k < 4; k++){
                    int ni = i + d[k][0];
                    int nj = j + d[k][1];
                    if(ni < 0 || ni >= s.size() || nj < 0 || nj >= s[i].length())
                        continue;
                    if(s[ni][nj] == 'P') return 0;
                    if(s[ni][nj] == 'O'){
                        for(int l = 0; l < 4; l++){
                            int nni = ni + d[l][0];
                            int nnj = nj + d[l][1];
                            if(nni < 0 || nni >= s.size() ||
                               nnj < 0 || nnj >= s[i].length() || (nni == i && nnj == j))
                                continue;
                            if(s[nni][nnj] == 'P') return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto x : places){
        answer.push_back(check(x));
    }
    return answer;
}
