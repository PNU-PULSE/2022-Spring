#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	long long time[N];
	long long max_time = 0;

	for (int i = 0; i < N; i++) {
        cin >> time[i];
        if (time[i] > max_time) max_time = time[i];
	}

	long long left = 0, right = max_time * M, min_time = right, mid, people;

	while (left <= right) {
        mid = (left + right) / 2;
        people = 0;

        for (int i = 0; i < N; i++) people += mid / time[i];

        if (people < M) left = mid + 1;
        else {
            right = mid - 1;
            if (min_time > mid) min_time = mid;
        }
    }

	cout << min_time;
  return 0;
}
