#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int water[N];
	for (int i = 0; i < N; i++) cin >> water[i];

    int left = 0, right = N - 1;
    int min_water = 2000000000, min_left = water[left], min_right = water[right];

    while (left < right) {
        if (min_water > abs(water[left] + water[right])) {
                min_water = abs(water[left] + water[right]);
                min_left = water[left];
                min_right = water[right];
        }

        if (right - 1 != left && abs(water[left] + water[right]) < abs(water[left] + water[right - 1])) left++;
        else right--;
    }

    cout << min_left << " " << min_right;

    return 0;
}

