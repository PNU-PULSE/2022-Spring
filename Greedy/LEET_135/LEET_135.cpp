class Solution {
public:
    int desending(vector<int>& ratings, int start) {
        int i;
        for(i = start + 1; i < ratings.size() && (i == 0 || ratings[i] < ratings[i - 1]); ++i);
        return i - 1;
    }
    int candy(vector<int>& ratings) {
        int n = 0;
        
        int i = 0;
        int end = 0;
        int pre = 1;
        int gap;
        
        end = desending(ratings, i);
        if (end == i) {
            n += 1;
            i = i + 1;
        }
        else {
            gap = end - i;
            n += (gap + 2) * (gap + 1) / 2;
            i = end + 1;
        }

        while (i < ratings.size()) {
            end = desending(ratings, i);
            if (end == i) {
                if (ratings[i - 1] == ratings[i]) {
                    pre = 1;
                }
                else {
                    pre += 1;
                }
                n += pre;
            }
            else {
                if (ratings[i - 1] == ratings[i]) {
                    pre = 1;
                }
                else {
                    pre += 1;
                }
                gap = end - i + 1;
                if (gap < pre) {
                    n+= pre - gap;
                }
                n += (gap + 1) * gap / 2;
                pre = 1;
                i = end;
            }
            ++i;
        }

        return n;
    }
};