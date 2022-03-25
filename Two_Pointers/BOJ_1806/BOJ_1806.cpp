#include <iostream>
#define MAX 100000
using namespace std;

void fastio();
void input();
void solution();
void output();

int n, s;
int report[MAX];
int minVal = MAX + 1;

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
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> report[i];
    }
}

void solution(){
    int partialSum = 0, idx = 0;
    for(int i = 0; i < n; i++){
        while(true){
            if(partialSum >= s){
                minVal = min(minVal, idx - i);
                partialSum -= report[i];
                break;
            }
            if(idx == n) return;
            partialSum += report[idx];
            idx++;
        }
    }
}

void output(){
    (minVal == MAX + 1)? cout << 0 : cout << minVal;
}

