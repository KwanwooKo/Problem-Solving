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
#define INF (int)10000000
using namespace std;
typedef long long ll;
class BOJ1504 {
private:
    int n, e;
    vector<pair<int, int> > edges[801];
    int node_price[801];
    ll ans;
    int point1, point2;
public:
    BOJ1504() {
        cin >> n >> e;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            node_price[i] = INF;
        }
        for (int i = 0; i < e; i++) {
            int from, to, price;
            cin >> from >> to >> price;
            edges[from].push_back(make_pair(to, price));
            edges[to].push_back(make_pair(from, price));
        }
        cin >> point1 >> point2;
    }
    void init() {
        for (int i = 0; i <= n; i++) {
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
    void print(ll route1, ll route2) {
        if (route1 >= INF && route2 >= INF) {
            cout << -1 << endl;
        }
        else {
            ans = min(route1, route2);
            cout << ans << endl;
        }
    }
    void solve() {
        dijkstra(1);
        int start_to_point1 = node_price[point1];
        int start_to_point2 = node_price[point2];
        init();
        dijkstra(point1);
        int point1_to_point2 = node_price[point2];
        int point1_to_dest = node_price[n];
        init();
        dijkstra(point2);
        int point2_to_dest = node_price[n];
        int point2_to_point1 = node_price[point1];
        ll route1 = start_to_point1 + point1_to_point2 + point2_to_dest;
        ll route2 = start_to_point2 + point2_to_point1 + point1_to_dest;
        print(route1, route2);        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ1504 boj1504;
    boj1504.solve();
    return 0;
}