#include <stdio.h>
#include <vector>

using namespace std;

int n;
long long k;
int tree[200001][2];

void solve(int node) {
    int left = tree[node][0];
    int right = tree[node][1];

    if (left == -1 && right == -1) {
        printf("%d\n", node);
        return;
    }
    else if (left == -1) {
        solve(right);
    }
    else if (right == -1) {
        solve(left);
    }
    else if (k % 2 == 1) {
        k = k / 2 + 1;
        solve(left);
    }
    else {
        k = k / 2;
        solve(right);
    }
}

int main() {
    scanf(" %d", &n);
    for (int i=1; i<=n; i++)
        scanf(" %d %d", &tree[i][0], &tree[i][1]);
    scanf(" %lld", &k);

    solve(1);
}
