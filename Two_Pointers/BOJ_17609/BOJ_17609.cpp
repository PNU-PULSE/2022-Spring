#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int n = 0;
bool decide(string &temp, int num) {
	auto iter1 = temp.begin();
	auto iter2 = temp.begin(); 
    iter2 += (num - 1);
	for (int i = 0; i < num / 2; i++) { 
        if (*iter1 != *iter2) { 
            n = i; 
            return false; 
        }
        iter1++; iter2--; 
    }
	return true;
}
int main() {
	int num, tem;
	string temp, temp1, temp2;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		tem = temp.size();
		if (decide(temp, tem)) cout << "0" << endl;
		else {
			tem = tem - 2 * n - 1;
			temp1 = temp.substr(n, tem);
			temp2 = temp.substr(n + 1, tem);
			if (decide(temp1, tem)) { cout << "1" << endl; }
			else if (decide(temp2, tem)) { cout << "1" << endl; }
			else { cout << "2" << endl; }
		}
	}
}
