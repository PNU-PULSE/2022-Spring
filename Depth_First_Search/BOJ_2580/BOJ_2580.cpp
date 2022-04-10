#include <bits/stdc++.h>
using namespace std;
int arr[10][10],siz;
bool row[10][10],col[10][10],block[10][10];
vector<pair<int,int>> zero;
int square_num(int i,int j){
    return (i/3)*3 + j/3;
}
void print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}

bool dfs(int n){
    if(n == siz){print();return true;}
    int x = zero[n].first;
    int y = zero[n].second;
    for(int i=1;i<=9;i++){
        if(row[x][i] == false && col[y][i] == false && block[square_num(x,y)][i] == false){
            row[x][i] = col[y][i] = block[square_num(x,y)][i] = true;
            arr[x][y] = i;
            if(dfs(n+1)){return true;}
            row[x][i] = col[y][i] = block[square_num(x,y)][i] = false;
            arr[x][y] = 0;
        }
    }
    return false;
}

int main(){
    siz = 0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] != 0){
                row[i][arr[i][j]] = col[j][arr[i][j]] = block[square_num(i,j)][arr[i][j]] = true;
            }
            else{
                zero.push_back({i,j});
                siz++;
            }
        }
    }
    dfs(0);
    return 0;
}
