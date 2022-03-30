#include <bits/stdc++.h>
#define MAX 51
using namespace std;

void fastio();
void input();
void solution();
void output();

struct compare{
    bool operator()(const pair<long long, long long>& A, const pair<long long, long long>& B){
        if(A.first == B.first){
            return A.second > B.second;
        }
        return A.first > B.first;
    }
};

int l, n;
long long report[MAX];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, compare> pq;

int main(){
    fastio();
    input();
    solution();
    output();
}

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> l;
    report[0] = 0;
    for(int i = 1; i < l + 1; i++){
        cin >> report[i];
    }
    cin >> n;
}

void solution(){
    int cnt = n, cnt2 = 0;
    sort(report, report+l+1);
    for(int i = 0; i < l; i++){
        cnt2 = 0;
        if(i != 0){
            pq.push({1, report[i]});
            cnt--;
            cnt2++;
        }
        for(int j = report[i] + 1; j < (report[i + 1] + report[i])/2; j++){
            if(cnt2 > 100) break;
            pq.push({(report[i+1] - j)*(j - report[i]), j});
            pq.push({(report[i+1] - j)*(j - report[i]), report[i+1] + report[i] - j});
            cnt -= 2;
            cnt2 += 2;
        }
        if(((report[i + 1] + report[i]))%2 == 0){
            if((report[i+1] - report[i]) > 1){
                pq.push({((report[i + 1] - report[i])/2)*((report[i + 1] - report[i])/2), (report[i + 1] + report[i])/2});
                cnt--;
            }
        }
        else{
            if((report[i+1] - report[i]) > 1){
                pq.push({((report[i + 1] + report[i])/2 - report[i])*(report[i+1] - (report[i + 1] + report[i])/2), (report[i + 1] + report[i])/2});
                pq.push({((report[i + 1] + report[i])/2 - report[i])*(report[i+1] - (report[i + 1] + report[i])/2), (report[i + 1] + report[i])/2 + 1});
                cnt -= 2;
            }
        }
    }
    pq.push({1, report[l]});
    cnt--;
    int idx = 1;
    while(cnt > 0){
        pq.push({INT_MAX, report[l] + idx});
        cnt--;
        idx++;
    }
}

void output(){
    int cnt = n;
    while(cnt--){
        cout << pq.top().second << " ";
        pq.pop();
    }
}

