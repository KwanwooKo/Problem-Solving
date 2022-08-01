#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 1e9
using namespace std;
typedef long long ll;
int node_price[10001];
vector<pair<int, int>> edges[10001];
bool check[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i <= d; i++) {
        node_price[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        if (to - from <= price) continue;
        if (to > d) continue;
        edges[from].push_back({to, price});
    }
    // (노드, 비용)
    // 다익스트라 어케 쓰냐 대체...
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j < edges[i].size(); j++) {
            int from = i;
            int next = edges[i][j].first;
            int price = edges[i][j].second;
            node_price[next] = min(node_price[next], node_price[from] + price);
            for (int k = next + 1; k <= d; k++) {
                node_price[k] = min(node_price[k], node_price[k - 1] + 1);
            }
        }
    }
    cout << node_price[d] << endl;

//    for (int i = 0; i <= d; i++) {
//        printf("%5d", i);
//    }
//    cout << endl;
//    for (int i = 0; i <= d; i++) {
//        printf("%5d", node_price[i]);
//    }
//    cout << endl;
    return 0;
}
