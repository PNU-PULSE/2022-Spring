#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long int> parent(1, 0);
long long int npg[100001];
long long int ans = 0;
struct p{
    int l, u, v;
};
int f(p x, p y){
    return x.l > y.l;
}
int find(int k){
    if (k == parent[k]){
        return k;
    }
    else{
        return parent[k] = find(parent[k]);
    }
}
void merge(int a, int b, int w){
    int x, y;   x = find(a); y = find(b);
    ans += npg[x] * npg[y] * w;
    if (x < y){
        parent[y] = x;
        npg[x] += npg[y];
        npg[y] = 0;
    }
    else{
        parent[x] = y;
        npg[y] += npg[x];
        npg[x] = 0;
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<p> v;
    v.push_back({int(1e9), 0, 0});
    for (int i = 1; i < n; i++){
        parent.push_back(i);
        npg[i] = 1;
        int a, b, c;    cin >> a >> b >> c;
        v.push_back({c, a, b});
    }
    parent.push_back(n);
    npg[n] = 1;
    sort(v.begin(), v.end(), f);
    for (int i = 1; i < n; i++){
        merge(v[i].u, v[i].v, v[i].l);
    }
    cout << ans;
}