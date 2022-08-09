#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
int node_price[1001];
int in_degree[1001];
int ans[1001];
vector<int> edges[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i <= 1000; i++) {
            node_price[i] = 0;
            in_degree[i] = 0;
            ans[i] = 0;
            edges[i].clear();
        }
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> node_price[i];
            ans[i] = node_price[i];
        }
        for (int i = 0; i < k; i++) {
            int from, to;
            cin >> from >> to;
            edges[from].push_back(to);
            in_degree[to]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : edges[curr]) {
                ans[next] = max(ans[next], ans[curr] + node_price[next]);
                in_degree[next]--;
                if (in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }
        int dest;
        cin >> dest;
        cout << ans[dest] << endl;
    }

    return 0;
}