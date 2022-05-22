class Solution {
public:
    string minimizeResult(string expression) {
        int plusIdx = 0, idx1 = 0, idx2 = 0;
        int minVal = INT_MAX;
        string result;
        for(int i = 0; i < expression.length(); i++){
            if(expression[i] == '+'){
                plusIdx = i;
                break;
            }
        }
        for(int i = 0; i < plusIdx; i++){
            int left1 = (i != 0) ? stoi(expression.substr(0, i)) : 1;
            int left2 = stoi(expression.substr(i, plusIdx - i));
            for(int j = plusIdx + 1; j < expression.length(); j++){
                int right1 = (j != expression.length() - 1) ? stoi(expression.substr(j + 1, expression.length() - j - 1)) : 1;
                int right2 = stoi(expression.substr(plusIdx + 1, j - plusIdx));
                if(minVal > left1*(left2+right2)*right1){
                    minVal = left1*(left2+right2)*right1;
                    idx1 = i, idx2 = j;
                }
            }
        }
        result = expression.substr(0, idx1) + "(" + expression.substr(idx1, plusIdx - idx1) + "+" +
            expression.substr(plusIdx + 1, idx2 - plusIdx) + ")" + expression.substr(idx2 + 1, expression.length());

        return result;
    }
};
