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

// 1. 입력을 받아서 정렬
// 2. i = n부터 시작해서 데드라인이 n인 문제를 pq에 넣음
// 3. 이후 n번째로 풀 문제를 pq에서 한번 뽑아서 정하고 i--
// cf) i = k일 때 pq에 들어있는 문제는 모두 데드라인이 k 이상인 문제이기 때문에
//     1~k번째로 풀 수 있음. 그 중 가장 보상이 큰 문제를 정해 k에 푸는 것
