#include <bits/stdc++.h>
using namespace std;
int MAX=0;
vector<int> tree[10001];
int arr[10001];

int make_tree(int N){
    if(tree[N].empty()){return arr[N];}
    int left=0,right=0;
    vector<int> ans;
    for(auto K:tree[N]){ans.push_back(make_tree(K));}
    sort(ans.begin(),ans.end(),greater<>());
    int siz = ans.size();
    if(siz == 1){left = ans[0];}
    else {left = ans[0];right = ans[1];}
    if(left + right > MAX) MAX = left + right;

    left = left>right ? left : right;
    left += arr[N];
    arr[N] = left;
    return left; 
}

int main(){
    int N;cin>>N;
    int p,s,v;N--;
    for(int i=0;i<N;i++){
        cin>>p>>s>>v;
        arr[s] = v;
        tree[p].push_back(s);
    }
    make_tree(1);
    cout<<MAX;
}
