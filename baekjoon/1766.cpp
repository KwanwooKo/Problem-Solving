#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;

class Solution {
    private:
        priority_queue<int, vector<int>, greater<int> > pq;
        int n, m;
        int in_degree[32001];
        vector<int> edges[32001];
        bool check[32001];
        vector<int> ans;
    public:
        Solution() {
            cin >> n >> m;
            memset(in_degree, 0, sizeof(in_degree));
            for (int i = 0; i < m; i++) {
                int from, to;
                cin >> from >> to;
                in_degree[to]++;
                edges[from].push_back(to);
            }
            for (int i = 1; i <= n; i++) {
                if (in_degree[i] == 0) {
                    pq.push(i);
                    check[i] = true;
                }
            }
        }
        void solve() {
            while (!pq.empty()) {
                int cur = pq.top();
                pq.pop();
                cout << cur << ' ';
                for (int next : edges[cur]) {
                    if (check[next]) continue;
                    in_degree[next]--;
                    if (in_degree[next] == 0) {
                        pq.push(next);
                    }
                }
            }
            cout << endl;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
