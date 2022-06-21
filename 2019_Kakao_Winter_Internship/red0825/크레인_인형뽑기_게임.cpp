#include <string>
#include <vector>

using namespace std;

vector<int> R;

int check(){
    int result = 0;
    while(R.size() >= 2 && *R.rbegin() == *(R.rbegin() + 1)){
        R.pop_back();
        R.pop_back();
        result += 2;
    }
    return result;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for(auto x : moves){
        for(int i = 0; i < board.size(); i++){
            if(board[i][x - 1] != 0){
                R.push_back(board[i][x - 1]);
                answer += check();
                board[i][x - 1] = 0;
                break;
            }
        }
    }
    return answer;
}
