#include <bits/stdc++.h>

using namespace std;

int T, N;
int day;
int feed[2][6];

bool isPosible(int a){
    int sum = 0;
    for(int i=0; i<6; ++i)
        sum += feed[a][i];

    if(sum <= N) return true;
    else return false;
}

void nextDay(int from, int to){
    int tmp;
    for(int i=0; i<6; ++i){
        tmp = feed[from][i]; // origin
        tmp += feed[from][(i+1)%6]; // left pig
        tmp += feed[from][(i+6-1)%6]; // right pig
        tmp += feed[from][(i+3)%6]; // opposite pig

        feed[to][i] = tmp;
    }
}

int main(){
    cin >> T;

    for(int t=0; t<T; ++t){
        cin >> N;

        for(int i=0; i<6; ++i)
            cin >> feed[1][i];

        day = 0;
        while(true){
            day++;

            if(!isPosible(day % 2))
                break;

            nextDay(day%2, (day+1)%2);

        }

        cout << day << endl;
    }

    return 0;
}
