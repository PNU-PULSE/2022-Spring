class Solution {
public:
    string expr;
    int stoi(string e){
        int res = 0;
        for(auto s : e) {
            res *= 10;
            res += s - '0';
        }
        return res;
    }
    string slice(int l, int r) {
        string out="";
        for(int i = l; i < r; ++i) {
            out += expr[i];
            //cout << expr[i] << ' ';
        }
        //cout << out << endl;
        return out;
    }
    string minimizeResult(string expression) {
        int p_idx;
        long long minimum = 9876543210;
        string res;
        this -> expr = expression;
        string l1,l2, r1,r2;
        for(p_idx = 0; p_idx < expression.size() - 1 && expression[p_idx] != '+'; ++p_idx);
        for(int i = 0; i< p_idx;++i) { // i 앞에서
            for(int j = p_idx + 1;j<expression.size(); ++j){ // j 뒤에서
                //cout << i << ' ' << j << endl;
                if (i == 0) {
                    l1 = "";
                    l2 = slice(0, p_idx);
                }
                else {
                    l1 = slice(0, i);
                    l2 = slice(i, p_idx);
                }
                if (j == expression.size() - 1) {
                    r1 = slice(p_idx + 1, expression.size());
                    r2 = "";
                }
                else {
                    r1 = slice(p_idx + 1, j + 1);
                    r2 = slice(j + 1, expression.size());
                }
                //cout << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 <<endl;
                int curr = (l1 == "" ? 1 : stoi(l1)) * (stoi(l2) + stoi(r1)) * (r2 == "" ? 1 : stoi(r2));
                if (minimum > curr) {
                    minimum = curr;
                    res = l1 + '(' + l2 + '+' + r1 + ')' + r2;
                }
            }
        }
        return res;
    }
};