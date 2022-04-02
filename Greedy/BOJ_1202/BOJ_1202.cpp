#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>> M_pq;
priority_queue<long long> V_pq;
priority_queue<int> C_pq;
long long sum = 0;

void make_sum(int C) {
    while (!M_pq.empty() && M_pq.top().first >= C) {
        V_pq.push(M_pq.top().second);
        M_pq.pop();
    }

    if (!V_pq.empty()) {
        sum += V_pq.top();
        V_pq.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int M, V;
	for (int i = 0; i < N; i++) {
        cin >> M >> V;
        M_pq.push({-M, V});
	}

	int C;
	for (int i = 0; i < K; i++) {
        cin >> C;
        C_pq.push(-C);
	}

	while (!C_pq.empty()) {
        make_sum(C_pq.top());
        C_pq.pop();
	}

	cout << sum;
}
