#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a.size()<b.size())
        return true;
    return false;
}
int find(vector<int> a, vector<int> b){
    for(size_t i=0;i<b.size();++i){
        size_t j=0;
        for(;j<a.size();++j)
            if(b[i] == a[j])
                break;
        if(j == a.size())
            return b[i];
    }
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> temp;
    vector<vector<int>> set;
    int num = 0;
    for(size_t i = 1; i<s.length()-1;++i){
        if (s[i] == '{'){
            temp = vector<int>();
            num = 0;
        }
        else if(s[i] == ','){
            temp.push_back(num);
            num = 0;
        }
        else if(s[i] == '}'){
            temp.push_back(num);
            set.push_back(temp);
        }
        else{
            num *= 10;
            num += s[i] - '0';
        }
    }
    sort(set.begin(),set.end(),comp);
    answer.push_back(set[0][0]);
    for(size_t i=1;i<set.size();++i){
        answer.push_back(find(answer, set[i]));
    }

    return answer;
}