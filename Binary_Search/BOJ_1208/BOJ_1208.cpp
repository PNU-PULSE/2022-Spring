#include <bits/stdc++.h>

using namespace std;

int n,s;

vector<int> leftv;
vector<int> rightv;

map<int, long long> leftm;
map<int, long long> rightm;

void input();
void leftsub(int idx, int sum);
void rightsub(int idx, int sum);	


int main() {
	
    input();
	
	leftsub(0,0);
	rightsub(0,0);
	
	long long ans = 0;

	for(auto it:leftm){
		int value = it.first;
		long long lCount = it.second;
		long long rCount = rightm[s-value];
        
		ans += rCount * lCount;
		if(s==value && rCount==0){
			ans += lCount;
		}
	}
    
    if(s==0) ans--;
	cout<<ans;
}



void input(){
	cin>>n>>s;
    
	int temp;
	for(int i=0;i<n/2;i++){
		cin>>temp;
		leftv.push_back(temp);
	}
	for(int i=n/2;i<n;i++){
		cin>>temp;
		rightv.push_back(temp);
	}
}
void leftsub(int idx, int sum){
	if(idx==leftv.size()){
		leftm[sum]++;
		return;
	}
	leftsub(idx+1,sum+leftv[idx]);
	leftsub(idx+1,sum);		
}
void rightsub(int idx, int sum){
	if(idx==rightv.size()){
		rightm[sum]++;
		return;
	}
	rightsub(idx+1,sum+rightv[idx]);
	rightsub(idx+1,sum);
}
