#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n, m, r, index;
        vector<int> edges[100001];
        bool check[100001];
        int answer[100001];
    public:
        Solution() {
            cin >> n >> m >> r;
            index = 1;
            for (int i = 0; i < m; i++) {
                int from, to;
                cin >> from >> to;
                edges[from].push_back(to);
                edges[to].push_back(from);
            }
            for (int i = 1; i <= n; i++) {
                sort(edges[i].begin(), edges[i].end(), greater<>());
            }
        }
        void dfs(int cur) {
            answer[cur] = index++;
            for (int next : edges[cur]) {
                if (check[next]) continue;
                check[next] = true;
                dfs(next);
            }
        }
        void printAns() {
            for (int i = 1; i <= n; i++) {
                cout << answer[i] << endl;
            }
        }
        void solve() {
            check[r] = true;
            dfs(r);
            printAns();
        }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
