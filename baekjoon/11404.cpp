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
int edges[101][101];
int node_price[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                edges[i][j] = 0;
            }
            else {
                edges[i][j] = INF;
            }
        }
        node_price[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        edges[from][to] = min(edges[from][to], price);
    }


    // j에서 i를 거쳐서 k 로 간다고 생각
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                edges[j][k] = min(edges[j][k], edges[j][i] + edges[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << edges[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}