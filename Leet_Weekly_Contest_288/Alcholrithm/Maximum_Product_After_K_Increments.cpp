class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto num : nums) {
            pq.push(num);
        }
        
        while(k > 0) {
            int top = pq.top();
            pq.pop();
            pq.push(top + 1);
            --k;
        }
        
        long long res = 1;
        while (!pq.empty()) {
            res = (res * pq.top()) % 1000000007;
            pq.pop();
        }
        return res;
    }
};