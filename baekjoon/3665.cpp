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
class BOJ3665 {
private:
    int n, m;
    int in_degree[501];
    int grade[501];
    int edges[501][501];
    vector<int> ans;
    queue<int> q;
public:
    BOJ3665(int n) {
        this->n = n;
        for (int i = 0; i <= 500; i++) {
            in_degree[i] = 0;
            grade[i] = 0;
        }
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                edges[i][j] = 0;
            }
        }
    }
    void topologySort() {
        for (int i = 1; i <= n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for (int i = 1; i <= n; i++) {
                if (edges[curr][i] == 1) {
                    edges[curr][i] = 0;
                    in_degree[i]--;
                    if (in_degree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        if (ans.size() == n) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    void solve() {
        for (int i = 1; i <= n; i++) {
            cin >> grade[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                edges[grade[i]][grade[j]] = 1;
                in_degree[grade[j]]++;
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            if (edges[from][to]) {
                edges[from][to] = 0;
                edges[to][from] = 1;
                in_degree[from]++;
                in_degree[to]--;
            }
            else {  // to -> from
                edges[from][to] = 1;
                edges[to][from] = 0;
                in_degree[from]--;
                in_degree[to]++;
            }
        }
        topologySort();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        BOJ3665* boj3665 = new BOJ3665(n);
        boj3665->solve();
        delete boj3665;
    }
    return 0;
}