#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define point pair<int,int>
#define range(x,y) (x>=0 && x<N && y>=0 && y<M &&arr[x][y] != 2100000000 && is) 
int N,M,ans;
bool VISIT[50][50],is = true;
int arr[50][50];
int DYN[50][50];

void DFS(point p,int dep){

    int jump = arr[p.first][p.second];
    if(dep>ans) ans = dep;
    if(DYN[p.first][p.second] >= dep) return;
    else DYN[p.first][p.second] = dep;

    VISIT[p.first][p.second] = 1;
    
    bool b1=false,b2=false,b3=false,b4=false;
    if(range(p.first+jump,p.second)) {
        if(VISIT[p.first+jump][p.second]==1){cout<<"-1";is = false;return;} 
        else b1 = true;
    }
    if(range(p.first-jump,p.second)){
        if(VISIT[p.first-jump][p.second]==1){cout<<"-1";is = false;return;} 
        else b2 = true;
    }
    if(range(p.first,p.second+jump)){
        if(VISIT[p.first][p.second+jump]==1){cout<<"-1";is = false;return;} 
        else b3 = true;
    }
    if(range(p.first,p.second-jump)) {
        if(VISIT[p.first][p.second-jump]==1){cout<<"-1";is = false;return;} 
        else b4 = true;
    };
    if(b1) DFS({p.first+jump,p.second},dep+1);
    if(b2) DFS({p.first-jump,p.second},dep+1);
    if(b3) DFS({p.first,p.second+jump},dep+1);
    if(b4) DFS({p.first,p.second-jump},dep+1);
    VISIT[p.first][p.second] = 0;
    return;
}

int main(){
    string temp;
    cin>>N>>M;
    for(int i=0;i<N;i++){cin>>temp;for(int j=0;j<M;j++){
        arr[i][j] = temp[j]-'0';
        if(temp[j] == 'H') arr[i][j] = 2100000000;
        VISIT[i][j] = 0;
    }}
    DFS({0,0},1);
    if(is) cout<<ans<<endl;
}
