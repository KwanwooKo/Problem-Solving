#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int edges[1001][1001];
int node_price[1001];
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        node_price[i] = 1000000001;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            edges[i][j] = -1;
        }
    }
    int start, end;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        if (edges[from][to] == -1) {
            edges[from][to] = price;
        }
        else {
            edges[from][to] = min(edges[from][to], price);
        }
    }
    cin >> start >> end;
    node_price[start] = 0;
    pq.push(start);
    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        for (int i = 1; i <= n; i++) {
            int next = i;
            // 간선이 없는 경우는 continue
            if (edges[node][next] == -1) continue;
            if (node_price[node] + edges[node][next] < node_price[next]) {
                node_price[next] = node_price[node] + edges[node][next];
                pq.push(next);
            }
        }
    }
    cout << node_price[end] << endl;
    return 0;
}