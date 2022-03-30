#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;

void fastio();
void input();
void checkOverflow(int idx, int i, int j);
void solution();
void output();

int intTrans(char val);
char charTrans(int val);
string strTrans(int val);

string add(string a, string b);

int n, k;
string result;
string R[MAX];
int report[36][MAX];
pair<string, int> difference[36];

struct compare{
    bool operator()(const pair<string, int>& A, const pair<string, int>& B){
		if (A.first.length() == B.first.length()){
            return A.first > B.first;
		}
		return A.first.length() > B.first.length();
	}
};

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

void checkOverflow(int idx, int i, int j){
    if(report[idx][R[i].length() - j] == 36){

        int carryIdx = R[i].length() - j;

        while(report[idx][carryIdx] == 36){
            report[idx][carryIdx] = 0;
            carryIdx++;
            report[idx][carryIdx]++;
        }
    }
}

int intTrans(char val){
    return ('0' <= val && val <= '9')? val - '0' : val - 'A' + 10;
}

char charTrans(int val){
    return (val < 10)? val + '0' : val + 'A' - 10;
}

string strTrans(int val){
    string s;
    while(val){
        s += charTrans(val % 36);
        val /= 36;
    }
    reverse(s.begin(), s.end());
    return s;
}

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> R[i];
        for(int j = R[i].length() - 1; j >= 0; j--){

            int idx = intTrans(R[i][j]);
            report[idx][R[i].length() - 1 - j]++;

            checkOverflow(idx, i, j);
        }
    }
    cin >> k;
}

string add(string a, string b){
    string c;
    int sum = 0;
    while(!a.empty() || !b.empty() || sum){
        if(!a.empty()){
            sum += intTrans(a.back());
            a.pop_back();
        }
        if(!b.empty()){
            sum += intTrans(b.back());
            b.pop_back();
        }
        c.push_back(charTrans(sum%36));
        sum /= 36;
    }
    reverse(c.begin(), c.end());
    return c;
}

void solution(){
	for (int i = 0; i < 35; i++) {
		string diff;
		for (int j = 0; j < MAX; j++) {
			if (report[i][j]) {
				string s = strTrans(report[i][j] * (35-i)) + string(j, '0');
				diff = add(diff, s);
			}
		}
		difference[i] = {diff, i};
	}

	sort(difference, difference + 36, compare());

	for (int i = 0; i < k; i++){

		char c = (charTrans(difference[i].second));

        for (int j = 0; j < n; j++) {
            for(int k = 0; k < R[j].length(); k++){
                if(c == R[j][k]) R[j][k] = 'Z';
            }
        }
	}

	for (int i = 0; i < n; i++){
		result = add(result, R[i]);
	}
}

void output(){
    cout << result;
}

