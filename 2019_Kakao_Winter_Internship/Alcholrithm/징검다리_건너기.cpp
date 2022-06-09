#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int search(vector<int> stones, int l, int r, int k){
    int mid = (r + l) / 2;
    if(l>r)
        return 0;
    int cnt{};
    size_t i;
    for(i=0;i<stones.size();++i){
        if(stones[i]<mid)
            ++cnt;
        else
            cnt = 0;
        if(cnt == k){
            return search(stones, l, mid - 1, k);
        }
    }
    if (i==stones.size())
        return max(search(stones, mid + 1, r, k),mid);
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int r = *max_element(stones.begin(), stones.end());
    answer = search(stones, 1, r, k);
    return answer;
}