#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int mid = -10001;
priority_queue<int, vector<int>, greater<int>> pq_l;
priority_queue<int> pq_s;

void out_num(int num) {
    if (mid == -10001) {
        mid = num;
    }
    else {
        if (num > mid) pq_l.push(num);
        else pq_s.push(num);

        if (pq_l.size() == pq_s.size() + 2) {
            pq_s.push(mid);
            mid = pq_l.top();
            pq_l.pop();
        }
        if (pq_s.size() > pq_l.size()) {
            pq_l.push(mid);
            mid = pq_s.top();
            pq_s.pop();
        }
    }

    cout << mid << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
        cin >> num;
        out_num(num);
	}

    return 0;
}
