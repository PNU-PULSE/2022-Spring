class Solution {
public:
    string minimizeResult(string expression) {
        string a = "", b = "";
        bool next = false;
        for (char c: expression) {
            if (c != '+' && !next) {
                a += c-'0';
            } else if (c == '+') {
                next = !next;
            } else {
                b += c-'0';
            }
        }

        int ret = 1234567890;
        int i1, j1, c1, d1, e1, f1;
        for (int i=0; i<a.size(); i++) {
            int c=0, d=0;
            if (i == 0) c = 1;
            for (int k=0; k<i; k++) {
                c *= 10;
                c += a[k];
            }
            for (int k=i; k<a.size(); k++) {
                d *= 10;
                d += a[k];
            }

            for (int j=1; j<=b.size(); j++) {
                int e=0, f=0;
                if (j == b.size()) f = 1;
                for (int k=0; k<j; k++) {
                    e *= 10;
                    e += b[k];
                }
                for (int k=j; k<b.size(); k++) {
                    f *= 10;
                    f += b[k];
                }

                if (ret > min(ret, c*(d+e)*f)) {
                    ret = min(ret, c*(d+e)*f);
                    i1=i; j1=j; c1=c; d1=d; e1=e; f1=f;
                }
            }
        }

        string str = "";
        if (i1 != 0)
            str += to_string(c1);
        str += "(";
        str += to_string(d1);
        str += "+";
        str += to_string(e1);
        str += ")";
        if (j1 != b.size())
            str += to_string(f1);

        return str;
    }
};
