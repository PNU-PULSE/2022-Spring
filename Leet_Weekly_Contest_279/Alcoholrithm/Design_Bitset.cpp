class Bitset {
    vector<short> bits;
    int cnt;
    bool is_flip;
    string str;
public:
    Bitset(int size) {
        this->bits = vector<short>(size);
        cnt = 0;
        is_flip = false;
        str.resize(size);
        fill (str.begin(), str.end(), '0');
    }
    
    void fix(int idx) {
        if (this->bits[idx] == is_flip){
            this->bits[idx] = !is_flip;
            ++this->cnt;
        }
    } 
    
    void unfix(int idx) {
        if (this->bits[idx] == !is_flip){
            this->bits[idx] = is_flip;
            --this->cnt;
        }
    }
    
    void flip() {
        is_flip = !is_flip;
        cnt = bits.size() - cnt;
    }
    
    bool all() {
        return cnt == bits.size();
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return this -> cnt;
    }
    
    string toString() {
        for(int i = 0; i < bits.size(); ++i){
            str[i] = bits[i] == is_flip ? '0' : '1';
        }
        return str;
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