#include <bits/stdc++.h>
using namespace std;

int arr[101][101],R,C;
struct fish{int ID;int x;int y;int speed;int direct; int size;bool alive;};
vector<fish> shark;

pair<int,int> move(int &now , int direct,int &speed){
    int move = speed,tmp;
    if(direct == 1 || direct == 2){
        move = move % (R*2-2);
        while(move != 0){
            if(direct == 1){if(now==1){direct = 2; continue;} now--; move--;}
            else{if(now == R){direct = 1;continue;}now++;move--;}
        }
    }
    else{
        move = move%(C*2-2);
        while(move!=0){
            if(direct == 4){if(now==1){direct = 3;continue;}now--; move--;}
            else{if(now == C){direct = 4;continue;}now++;move--;}
        }
    }
    return {now,direct};
}

int main(){
    ifstream fin;
    fin.open("in.txt");
    int M,r,c,s,d,z,x,y,speed,direct,siz,answer = 0; fin>>R>>C>>M;
    for(int i=1;i<=R;i++){for(int j=1;j<=C;j++) arr[i][j] = -1; }
    shark.resize(M+1);
    for(int i=0;i<M;i++){
        // scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
        fin>>r>>c>>s>>d>>z;
        shark[i] = {i,r,c,s,d,z,true};
        if(arr[r][c] == -1){arr[r][c] = i;}
        else{
            if(shark[arr[r][c]].size > shark[i].size){shark[i].alive = false;}
            else{shark[arr[r][c]].alive = false; arr[r][c] = i;}
        }
    }
    pair<int,int> go;
    for(int i=1;i<=C;i++){
        c = 1;
        while(arr[c][i] == -1){
            c++;
            if(c>R) break;
        }
        if(c<=R){answer += shark[arr[c][i]].size; shark[arr[c][i]].alive = false;}
        vector<vector<int>> temp(R+1 , vector<int> (C+1,-1));


        for(int j=0;j<M;j++){
            if(shark[j].alive == false) continue;
            x=shark[j].x , y=shark[j].y , speed = shark[j].speed, siz = shark[j].size , direct = shark[j].direct; 
            if(direct == 1 || direct == 2){
                go = move(x,direct,speed);
                shark[j].x = go.first; shark[j].direct = go.second;
                x = shark[j].x;
            }
            else{
                go = move(y,direct,speed);
                shark[j].y = go.first; shark[j].direct = go.second;
                y = shark[j].y;
            }
            
            if(temp[x][y] == -1) {temp[x][y] = j;}
            else{
                if(shark[temp[x][y]].size > shark[j].size){shark[j].alive = false;}
                else{shark[temp[x][y]].alive = false; temp[x][y] = j;}
            }
        }
        for(int r=1;r<=R;r++){
            for(int c=1;c<=C;c++){
                arr[r][c] = temp[r][c];
            }
        }
    }
    cout<<answer;
}
