#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct compare {
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if (p1.second != p2.second) return p1.first < p2.first;
        else return p1.first < p2.first;
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> inp;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        inp.push({a, b});
    }

    priority_queue<int, vector<int>, less<int>> pq;
    long long sum = 0;
    for (int i = n; i > 0; i--) {
        while (!inp.empty() && inp.top().first == i) {
            pq.push(inp.top().second);
            inp.pop();
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
}
