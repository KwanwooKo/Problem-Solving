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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        // c 가 시작지점
        int n, d, c;
        cin >> n >> d >> c;
        vector<pair<int, int>> edges[n + 1];
        vector<int> node_price(n + 1);
        for (int i = 1; i <= n; i++) {
            node_price[i] = INF;
        }
        for (int i = 0; i < d; i++) {
            int from, to, price;
            cin >> to >> from >> price;
            edges[from].push_back({to, price});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, c});
        node_price[c] = 0;
        while (!pq.empty()) {
            int price = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (int i = 0; i < edges[node].size(); i++) {
                int next = edges[node][i].first;
                int next_price = edges[node][i].second;
                if (price + next_price < node_price[next]) {
                    node_price[next] = price + next_price;
                    pq.push({node_price[next], next});
                }
            }
        }
        int ans = 0;
        int ans_node = 0;
        for (int i = 1; i <= n; i++) {
            if (node_price[i] != INF) {
                ans_node++;
                if (ans < node_price[i]) {
                    ans = node_price[i];
                }
            }
        }
        cout << ans_node << ' ' << ans << endl;
    }
    return 0;
}