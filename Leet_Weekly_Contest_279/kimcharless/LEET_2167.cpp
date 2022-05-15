class Solution {
public:
    int minimumTime(string str) {
        int ans=9999999,siz = str.size();
        vector<int> left(siz+1,0),right(siz+1,0);
        left[0] = str[0]-'0'; right[siz-1] = str[siz-1] -'0';
        for(int i=1;i<siz;i++){
            if(str[i] == '0') {left[i] = left[i-1];}
            else{left[i] = min(i+1 , left[i-1]+2);}
        }
        for(int i=siz-2;i>=0;i--){
            if(str[i] == '0') {right[i] = right[i+1];}
            else{right[i] = min(siz-i,right[i+1]+2);}
        }
        for (int i=0;i<siz;i++){ans = min(ans, left[i]+right[i+1]);}
        return ans;
    }
};
