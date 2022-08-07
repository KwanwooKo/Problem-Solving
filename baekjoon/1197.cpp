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
int disjoint_sets[10001];
vector<tuple<int, int, int>> edges;
int find_parents(int node) {
    while (1) {
        if (disjoint_sets[node] == node) {
            break;
        }
        node = disjoint_sets[node];
    }
    return node;
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
    int v, e;
    cin >> v >> e;
    // 자기 자신을 root로 초기화
    for (int i = 1; i <= 10000; i++) {
        disjoint_sets[i] = i;
    }
    for (int i = 0; i < e; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        edges.push_back({price, from, to});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (int i = 0; i < e; i++) {
        int price = get<0>(edges[i]);
        int from = get<1>(edges[i]);
        int to = get<2>(edges[i]);
        if (find_parents(from) == find_parents(to)) continue;
        make_sets(from, to);
        ans += price;
    }
    cout << ans << endl;
    return 0;
}