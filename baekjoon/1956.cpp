#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 1e9
using namespace std;
typedef long long ll;
int edges[401][401];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            edges[i][j] = INF;
        }
    }
    for (int i = 0; i < e; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        edges[from][to] = price;    
    }
    // j -> i -> k
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                edges[j][k] = min(edges[j][k], edges[j][i] + edges[i][k]);
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= v; i++) {
        if (edges[i][i] < INF) {
            ans = min(ans, edges[i][i]);
        }
    }
    // cout << endl;
    // for (int i = 1; i <= v; i++) {
    //     for (int j = 1; j <= v; j++) {
    //         cout << edges[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    if (ans == INF) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}