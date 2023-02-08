#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n, m;
        vector<int> edges[101];
        bool check[101];
    public:
        Solution() {
            cin >> n >> m;
            for (int i = 0; i < m; i++) {
                int from, to;
                cin >> from >> to;
                edges[from].push_back(to);
                edges[to].push_back(from);
            }
        }
        void dfs(int cur) {
            for (int next : edges[cur]) {
                if (check[next]) continue;
                check[next] = true;
                dfs(next);
            }
        }
        void printAns() {
            int ans = 0;
            for (int i = 2; i <= n; i++) {
                if (check[i]) ans++;
            }
            cout << ans << endl;
        }
        void solve() {
            dfs(1);
            printAns();
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
