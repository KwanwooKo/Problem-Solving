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
int node_price[200001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    fill(node_price, node_price + 200000, INF);
    queue<int> q;
    q.push(n);
    node_price[n] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node * 2 <= 200000) {
            if (node_price[node] < node_price[node * 2]) {
                node_price[node * 2] = node_price[node];
                q.push(node * 2);
            }
        }
        if (node - 1 >= 0) {
            if (node_price[node] + 1 < node_price[node - 1]) {
                node_price[node - 1] = node_price[node] + 1;
                q.push(node - 1);
            }
        }
        if (node + 1 <= 100000) {
            if (node_price[node] + 1 < node_price[node + 1]) {
                node_price[node + 1] = node_price[node] + 1;
                q.push(node + 1);
            }
        }
    }
//    for (int i = 0; i <= k; i++) {
//        cout << node_price[i] << ' ';
//    }
//    cout << endl;
    cout << node_price[k] << endl;
    return 0;
}