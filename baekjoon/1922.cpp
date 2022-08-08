#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
int disjoint_sets[1001];
vector<tuple<int, int, int>> edges;
int find_parents(int node) {
    if (node != disjoint_sets[node]) {
        disjoint_sets[node] = find_parents(disjoint_sets[node]);
    }
    return disjoint_sets[node];
}
void make_sets(int a, int b) {
    a = find_parents(a);
    b = find_parents(b);
    if (a < b) {
        disjoint_sets[b] = a;
    }
    else {
        disjoint_sets[a] = b;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        if (from > to) {
            swap(from, to);
        }
        edges.push_back({price, from, to});
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) {
        disjoint_sets[i] = i;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int price = get<0>(edges[i]);
        int from = get<1>(edges[i]);
        int to = get<2>(edges[i]);
        // 둘이 같은 집합이면
        if (find_parents(from) == find_parents(to)) continue;
        make_sets(from, to);
        ans += price;
    }
    cout << ans << endl;
    return 0;
}