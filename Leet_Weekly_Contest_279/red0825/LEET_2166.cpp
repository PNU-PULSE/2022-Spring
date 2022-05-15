class Bitset {
public:
    string bitset;
    int ssize;
    int cnt;
    bool checkone;
    bool checkall;
    bool fliped;
    Bitset(int size) {
        ssize = size;
        for(int i = 0; i < size; i++){
            bitset.push_back('0');
        }
        cnt = 0;
        checkone = false;
        checkall = false;
        fliped = false;
    }

    void fix(int idx) {
        if(fliped){
            if(bitset[idx] == '1'){
                bitset[idx] = '0';
                checkone = true;
                cnt++;
                if(cnt == ssize) checkall = true;
            }
        }
        else{
            if(bitset[idx] == '0'){
                bitset[idx] = '1';
                checkone = true;
                cnt++;
                if(cnt == ssize) checkall = true;
            }
        }
    }

    void unfix(int idx) {
        if(fliped){
            if(bitset[idx] == '0'){
                bitset[idx] = '1';
                checkall = false;
                cnt--;
                if(cnt == 0) checkone = false;
            }
        }
        else{
            if(bitset[idx] == '1'){
                bitset[idx] = '0';
                checkall = false;
                cnt--;
                if(cnt == 0) checkone = false;
            }
        }
    }

    void flip() {
        cnt = ssize - cnt;
        if(cnt == 0){
            checkone = false;
            checkall = false;
        }
        else if(cnt == ssize){
            checkone = true;
            checkall = true;
        }
        fliped = !fliped;
    }

    bool all() {
        return checkall;
    }

    bool one() {
        return checkone;
    }

    int count() {
        return cnt;
    }

    string toString() {
        if(fliped){
            string bitset2 = bitset;
            for(int i = 0; i < bitset2.length(); i++){
                bitset2[i] = (bitset2[i] == '1') ? '0' : '1';
            }
            return bitset2;
        }
        else return bitset;
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
