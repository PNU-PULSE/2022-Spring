// 시간초과 떠서 모든 함수를 O(1)로 작동하도록 만듬

class Bitset {
public:
    vector<bool> bits;
    vector<bool> rev;
    int ones, zeros;

    Bitset(int size) {
        bits.resize(size);
        rev.resize(size);
        for (int i=0; i<rev.size(); i++) rev[i] = 1;
        zeros = size;
        ones = 0;
    }

    void fix(int idx) {
        if (bits[idx] == 0) {
            zeros--;
            ones++;
            bits[idx] = 1;
            rev[idx] = 0;
        }
    }

    void unfix(int idx) {
        if (bits[idx] == 1) {
            zeros++;
            ones--;
            bits[idx] = 0;
            rev[idx] = 1;
        }
    }

    void flip() {
        swap(bits, rev);
        swap(ones, zeros);
    }

    bool all() {
        return (zeros == 0);
    }

    bool one() {
        return (ones != 0);
    }

    int count() {
        return ones;
    }

    string toString() {
        string s;
        for (bool i: bits) {
            if (i) s.push_back('1');
            else s.push_back('0');
        }
        return s;
    }
};
