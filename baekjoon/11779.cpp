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
class BOJ11779 {
private:
    int n, m;
    int start, end;
    int route_prev[1001];
    stack<int> ans;
    vector<pair<int, int> > edges[1001];
    int node_price[1001];
public:
    BOJ11779() {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            node_price[i] = INF;
        }
        for (int i = 1; i <= n; i++) {
            route_prev[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int from, to, price;
            cin >> from >> to >> price;
            edges[from].push_back(make_pair(to, price));
        }
        cin >> start >> end;
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
                if (node_price[curr] + edge_price < node_price[next]) {
                    node_price[next] = node_price[curr] + edge_price;
                    route_prev[next] = curr;
                    pq.push(make_pair(-node_price[next], next));
                }
            }
        }
    }
    void print() {
        cout << node_price[end] << endl;
        cout << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.top() << ' ';
            ans.pop();
        }
        cout << endl;
    }
    void solve() {
        dijkstra(start);
        int curr = end;
        while (1) {
            if (curr == start) {
                ans.push(curr);
                break;
            }
            ans.push(curr);
            curr = route_prev[curr];
        }
        print();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ11779 boj11779;
    boj11779.solve();
    return 0;
}