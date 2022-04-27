#include <iostream>
#include <algorithm>
using namespace std;

void fastio();
void input();
void solution();
void output();

int x, b;
string result;

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
    cin >> x >> b;
}

void solution(){
	int nx = x, nb = abs(b), temp;
	if(b > 0) nx = abs(nx);
	while(nx != 0){
        temp = nx % nb;
        if(temp < 0) temp += nb;
        result += (char)('0' + temp);
        nx = (nx - temp) / b;
    }
    if(result.length() == 0) result = "0";
    reverse(result.begin(), result.end());
    if(b > 0 && x < 0) result = "-" + result;
}

void output(){
    cout << result;
}

