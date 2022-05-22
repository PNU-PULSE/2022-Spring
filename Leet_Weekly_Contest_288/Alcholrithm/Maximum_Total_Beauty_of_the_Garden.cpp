using ll = long long;

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        
        vector<ll> pre_sum(1);
        sort(flowers.begin(), flowers.end());
        for(auto& flower : flowers) {
            flower = min(flower, target);
            pre_sum.push_back(pre_sum.back() + static_cast<ll>(flower));
        }
        
        ll N = flowers.size();
        ll partial_num = N;
        ll answer = 0;
        
        for(ll full_num = 0; full_num <= N; ++full_num) {
            ll remained = newFlowers - (target * full_num - (pre_sum[N] - pre_sum[N - full_num]));
            if (remained < 0) {
                break;
            }
            for(partial_num = min(partial_num, N - full_num); 
                partial_num > 0 && flowers[partial_num - 1] * partial_num - pre_sum[partial_num] > remained; --partial_num);
                
                ll temp = partial_num && flowers[0] < target ? min<ll>(target - 1, (remained + pre_sum[partial_num]) / partial_num) : 0;
                answer = max(answer, full_num * full + temp * partial);
            
        }
        return answer;
    }
};