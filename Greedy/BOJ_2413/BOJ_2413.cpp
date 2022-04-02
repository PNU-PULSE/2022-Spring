#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i: v) cin >> i;

    vector<int> changed(n+1, 0);

    for (int cur: v) {
        if (changed[cur] != 0) continue;
        if (changed[cur-1] != 0 || cur == 1) {
            changed[cur] = cur;
        }
        else {
            changed[cur] = cur-1;
            changed[cur-1] = cur;
        }
    }

    for (int i: v) {
        cout << changed[i] << " ";
    }
}
