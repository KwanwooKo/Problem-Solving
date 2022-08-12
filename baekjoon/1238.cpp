#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ1238 {
private:
// node갯수, edges갯수, 도착지점
    int n, m, x;
    int ans[1001];
    vector<pair<int, int> > edges[1001];
    int node_price[1001];
public:
    BOJ1238() {
        cin >> this->n >> this->m >> this->x;
        for (int i = 1; i <= n; i++) {
            node_price[i] = INF;
        }
        for (int i = 0; i < m; i++) {
            int from, to, price;
            cin >> from >> to >> price;
            edges[from].push_back(make_pair(to, price));
        }
    }
    void init() {
        for (int i = 1; i <= 1000; i++) {
            node_price[i] = INF;
        }
    }
    void dijkstra(int start) {
        priority_queue<pair<int, int>, vector<pair<int, int> > > pq;
        pq.push(make_pair(0, start));
        node_price[start] = 0;
        while (!pq.empty()) {
            int price = -pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if (node_price[curr] < price) continue;
            for (int i = 0; i < edges[curr].size(); i++) {
                int next = edges[curr][i].first;
                int edge_price = edges[curr][i].second;
                if (node_price[curr] + edge_price <= node_price[next]) {
                    node_price[next] = node_price[curr] + edge_price;
                    pq.push(make_pair(-node_price[next], next));
                }
            }
        }
    }
    // 1 -> x -> 1
    // 2 -> x -> 2
    // 3 -> x -> 3
    void solve() {
        dijkstra(x);
        for (int i = 1; i <= n; i++) {
            ans[i] += node_price[i];
        }

        for (int i = 1; i <= n; i++) {
            if (i == x) continue;
            init();
            dijkstra(i);
            ans[i] += node_price[x];
        }
        int max_price = -1;
        for (int i = 1; i <= n; i++) {
            max_price = max(max_price, ans[i]);
        }
        cout << max_price << endl;
    }
    void print() {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ1238 boj1238;
    boj1238.solve();
    return 0;
}