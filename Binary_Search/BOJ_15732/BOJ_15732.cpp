#include <stdio.h>
#include <vector>

using namespace std;

int n, k, d;
int rule[10000][3];

int main() {
    scanf(" %d %d %d", &n, &k, &d);
    for (int i=0; i<k; i++)
        scanf(" %d %d %d", &rule[i][0], &rule[i][1], &rule[i][2]);

    int ans;
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;

        long long cnt = 0;
        for (int i=0; i<k; i++) {
            int end = min(rule[i][1], mid);
            if (end >= rule[i][0])
                cnt += (end - rule[i][0]) / rule[i][2] + 1;
        }

        if (cnt >= d) {
            ans = mid;
            r = mid - 1;
        }
        else if (cnt < d) l = mid + 1;
    }

    printf("%d\n", r+1);
}
