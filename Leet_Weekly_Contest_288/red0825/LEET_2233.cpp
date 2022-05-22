class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long mod = 1e9 + 7;
        long long result = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : nums){
            pq.push(x);
        }
        for(int i = 0; i < k; i++){
            int j = pq.top();
            pq.pop();
            pq.push(j + 1);
        }
        while(!pq.empty()){
            result *= pq.top();
            result %= mod;
            pq.pop();
        }
        return result % mod;
    }
};
