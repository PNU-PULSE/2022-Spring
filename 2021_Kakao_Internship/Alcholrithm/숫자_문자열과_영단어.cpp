#include <vector>
#include <string>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<string,  int> m;
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;

    string temp;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            answer = answer * 10 + s[i] - '0';
        }
        else {
            temp += s[i];
            if (m.find(temp) != m.end()) {
                answer = answer * 10 + m[temp];
                temp.clear();
            }
        }
    }
    return answer;
}