#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
int disjoint_sets[200001];
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
    cin.tie(0), cout.tie(0);
    while (1) {
        int n, m, k, ans = 0;;
        cin >> n >> m;
        for (int i = 1; i <= 200000; i++) {
            disjoint_sets[i] = i;
        }
        if (n == 0 && m == 0) break;
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; i++) {
            int from, to, price;
            cin >> from >> to >> price;
            edges.push_back({price, from, to});
            ans += price;
        }
        sort(edges.begin(), edges.end());
        for (int i = 0; i < edges.size(); i++) {
            int price = get<0>(edges[i]);
            int from = get<1>(edges[i]);
            int to = get<2>(edges[i]);
            if (find_parents(from) != find_parents(to)) {
                make_sets(from, to);
                ans -= price;
            }
        }
        cout << ans << endl;
    }
    return 0;
}