#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321
using namespace std;
typedef long long ll;
vector<int> edges[20001];
int node_price[20001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty()) {
        int node = q.front().first;
        int price = q.front().second;
        q.pop();
        for (int next : edges[node]) {
            if (node_price[next] == 0) {
                node_price[next] = price + 1;
                q.push({next, price + 1});
            }
            else {
                if (node_price[next] > price + 1) {
                    node_price[next] = price + 1;
                    q.push({next, price + 1});
                }
            }
        }
    }
    int max_dist = 0;
    int ans_num = 0;
    int ans_count = 0;
    for (int i = 2; i <= n; i++) {
        if (max_dist < node_price[i]) {
            max_dist = node_price[i];
            ans_num = i;
        }

    }
    for (int i = 2; i <= n; i++) {
        if (node_price[i] == max_dist) {
            ans_count++;
        }
    }
    cout << ans_num << ' ' << max_dist << ' ' << ans_count << endl;
    return 0;
}