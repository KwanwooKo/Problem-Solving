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
int disjoint_sets[100001];
vector<tuple<int, int, int>> edges;
int find_parents(int node) {
    while (1) {
        if (node == disjoint_sets[node]) {
            break;
        }
        node = disjoint_sets[node];
    }
    return node;
}
void make_sets(int from, int to) {
    from = find_parents(from);
    to = find_parents(to);
    if (from < to) {
        disjoint_sets[to] = from;
    }
    else {
        disjoint_sets[from] = to;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        disjoint_sets[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        if (from > to) {
            swap(from, to);
        }
        edges.push_back({price, from, to});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    int max_price = -1;
    for (int i = 0; i < edges.size(); i++) {
        int price = get<0>(edges[i]);
        int from = get<1>(edges[i]);
        int to = get<2>(edges[i]);
        // 서로 같은 집합이면 간선 연결 x
        if (find_parents(from) == find_parents(to)) continue;
        make_sets(from, to);
        ans += price;
        max_price = max(max_price, price);
    }
    ans -= max_price;
    cout << ans << endl;
    return 0;
}