class Bitset {
public:
    string s = "";
    string flip_s = "";
    int cnt = 0;
    bool f = 0;
    
    Bitset(int size) {
        for (int i = 0; i < size; i++) {
            s += "0";
            flip_s += "1";
        }
    }
    
    void fix(int idx) {
        if (!f && s[idx] == '0') {
            s.replace(idx, 1, "1");    
            flip_s.replace(idx, 1, "0");
            cnt++;
        }
        if (f && s[idx] == '1') {
            s.replace(idx, 1, "0");    
            flip_s.replace(idx, 1, "1");
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if (!f && s[idx] == '1') {
            s.replace(idx, 1, "0");    
            flip_s.replace(idx, 1, "1");
            cnt--;
        }
        if (f && s[idx] == '0') {
            s.replace(idx, 1, "1");    
            flip_s.replace(idx, 1, "0");
            cnt--;
        }
    }
    
    void flip() {
        f = !f;
        cnt = s.length() - cnt;
    }
    
    bool all() {
        return (cnt == s.size());
    }
    
    bool one() {
        return (cnt > 0);
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        if (!f) return s;
        return flip_s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
