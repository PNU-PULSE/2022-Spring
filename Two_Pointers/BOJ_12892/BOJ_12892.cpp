#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, d;

int main() {
    cin >> n >> d;
    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int l = 0, r = 0;
    long long sum = v[0].second;
    long long ans = 0;
    while (true) {
        ans = max(ans, sum);

        if (r == n-1) break;

        r++;
        sum = sum + v[r].second;

        while (v[r].first - v[l].first >= d) {
            sum = sum - v[l].second;
            l++;
        }
    }

    cout << ans << endl;
}
