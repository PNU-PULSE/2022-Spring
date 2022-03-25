#include <iostream>
#define MAX 40001
using namespace std;

void fastio();
void input();
int  binarySearch();
void solution();
void output();

int n, pos = 1;
int report[MAX];
int dp[MAX];

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
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> report[i];
    }
}

int binarySearch(int val){
    int left = 1, right = pos, mid;
    while(left < right){
        mid = (left + right)/2;
        if(dp[mid] < val){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return right;
}

void solution(){
    dp[1] = report[1];
    for(int i = 2; i <= n; i++){
        if(dp[pos] < report[i]){
            dp[++pos] = report[i];
        }
        else{
            int idx = binarySearch(report[i]);
            dp[idx] = report[i];
        }
    }
}

void output(){
    cout << pos;
}

