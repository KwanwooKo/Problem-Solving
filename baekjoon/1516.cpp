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
int in_degree[501];
int node_price[501];
int ans[501];
vector<int> edges[501];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int price, from;
        cin >> price;
        node_price[i] = price;
        while (1) {
            cin >> from;
            if (from == -1) {
                break;
            }
            in_degree[i]++;
            edges[from].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = node_price[i];
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
        for (int i = 0; i < edges[curr].size(); i++) {
            int next = edges[curr][i];
            ans[next] = max(ans[next], ans[curr] + node_price[next]);
            in_degree[next]--;
            if (in_degree[next] == 0) {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}