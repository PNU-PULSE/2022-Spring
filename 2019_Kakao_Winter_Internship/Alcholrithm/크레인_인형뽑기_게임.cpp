#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> st(board.size());
    for(int i = board.size()-1;i>=0;--i)
        for(size_t j = 0;j<board[i].size();++j)
            if(board[i][j]!=0)
                st[j].push(board[i][j]);
    
    stack<int> res;
    
    for(size_t i=0;i<moves.size();++i){
        int l = moves[i] - 1;
        if(st[l].size()!=0){
            if (res.size()==0 || res.top()!=st[l].top())
                res.push(st[l].top());
            else{
                res.pop();
                ++answer;
                ++answer;
            }
            st[l].pop();
        }
    }

    return answer;
}