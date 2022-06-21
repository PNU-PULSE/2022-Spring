#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct compare{
    bool operator ()(vector<int> &A, vector<int> &B){
        return A.size() < B.size();
    }
};

vector<int> split(string input, char delimiter) {
    vector<int> res;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        res.push_back(stoi(temp));
    }
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> R;
    int i = 1;
    while(i < s.length() - 1){
        if(s[i] == '{'){
            int j = i;
            while(s[i] != '}'){
                i++;
            }
            R.push_back(split(s.substr(j + 1, i - j - 1), ','));
        }
        i += 2;
    }
    sort(R.begin(), R.end(), compare());
    for(auto x : R){
        for(auto y : x){
            if(answer.end() != find(answer.begin(), answer.end(), y)) continue;
            answer.push_back(y);
        }
    }
    return answer;
}
