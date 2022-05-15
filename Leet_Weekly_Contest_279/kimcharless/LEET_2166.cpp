class Bitset {
public:
    string str,flip_str;
    int COUNT;
    int siz;
    Bitset(int size) {
        COUNT = 0;
        siz = size;
        str.resize(size);
        flip_str.resize(size);
        for(int i=0;i<size;i++){str[i] = '0';flip_str[i] = '1';}
    }
    
    void fix(int idx) {
        if(str[idx] == '0') COUNT++;
        str[idx] = '1';
        flip_str[idx] = '0';
    }
    
    void unfix(int idx) {
        if(str[idx] == '1') COUNT--;
        str[idx] = '0';
        flip_str[idx] = '1';
    }
    
    void flip() {
        swap(str,flip_str);
        COUNT = siz-COUNT;
    }
    
    bool all() {
        if(siz == COUNT) return true;
        else return false;
    }
    
    bool one() {
        if(COUNT>0) return true;
        return false;
    }
    
    int count() {
        return COUNT;
    }
    
    string toString() {
        return str;
    }
};
