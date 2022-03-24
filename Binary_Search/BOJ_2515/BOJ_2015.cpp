#include iostream
#include vector
#include algorithm

using namespace std;

using mypair = pairint, int;

int main(void)
{
	ios_basesync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin  n  s;
	vectormypair vec(n + 1);  height, price;
	vectormypair dp(n + 1);  height, maximum_price
	for (int i = 1; i = n; ++i) {
		cin  vec[i].first  vec[i].second;
	}

	auto comp = [](mypair a, mypair b) {return a.first == b.first  a.second  b.second  a.first  b.first; };

	sort(vec.begin(), vec.end(), comp);


	for (int i = 1, idx, target; i = n; ++i) {
		target = vec[i].first - s;

		if (target = dp[i - 1].first) {
			dp[i] = mypair({ vec[i].first, dp[i - 1].second + vec[i].second });
		}
		else {
			idx = upper_bound(&dp[0], &dp[i], mypair({ target, -1 }), comp) - &dp[0] - 1;
			if (dp[idx].second + vec[i].second  dp[i - 1].second) {
				dp[i] = mypair({ vec[i].first, dp[idx].second + vec[i].second });
			}
			else {
				dp[i] = dp[i - 1];
			}
		}

	}

	cout  dp[n].second;
	return 0;
}