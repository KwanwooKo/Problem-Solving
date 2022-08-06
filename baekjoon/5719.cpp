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
int edges[500][500];
int node_price[500];
bool bfs_check[500];
int n, m;
void dijkstra(int node) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, node});
    while (!pq.empty()) {
        int price = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        // 최단거리가 아니면 넘겨줌
        if (node_price[curr] < price) continue;
        for (int i = 0; i < n; i++) {
            int next = i;
            // 간선 연결이 안 되어 있으면 pass
            if (edges[curr][next] == INF) continue;
            if (edges[curr][next] + price < node_price[next]) {
                node_price[next] = edges[curr][next] + price;
                pq.push({node_price[next], next});
            }
        }
    }
}
void bfs(int node, int start) {
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next = 0; next < n; next++) {
            if (edges[next][curr] == INF) continue;
            if (curr == next) continue;
            if (node_price[next] + edges[next][curr] != node_price[curr]) continue;
            edges[next][curr] = INF;
            q.push(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < 500; i++) {
            node_price[i] = INF;
            for (int j = 0; j < 500; j++) {
                if (i == j) {
                    edges[i][j] = 0;
                }
                else {
                    edges[i][j] = INF;
                }
            }
        }
        int start, dest;
        cin >> start >> dest;
        for (int i = 0; i < m; i++) {
            int from, to, price;
            cin >> from >> to >> price;
            edges[from][to] = price;
        }
        // 시작 지점 node 초기화
        node_price[start] = 0;
        dijkstra(start);

        bfs(dest, start);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (edges[i][j] == INF) {
        //             printf("%5s", "INF");
        //         }
        //         else {
        //             printf("%5d", edges[i][j]);
        //         }
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < n; i++) {
            node_price[i] = INF;
        }
        dijkstra(start);
        if (node_price[dest] >= INF) {
            cout << -1 << endl;
        }
        else {
            cout << node_price[dest] << endl;
        }
    }
    return 0;
}