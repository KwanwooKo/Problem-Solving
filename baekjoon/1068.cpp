#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n, root, erase, ans;
        vector<int> node[51];
    public:
        Solution() {
            cin >> n;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                if (num == -1) 
                    root = i;
                else
                    node[num].push_back(i);
            }
            cin >> erase;
            ans = 0;
        }
        void solve() {
            if (root == erase) {
                cout << "0" << endl;
            } else {
                dfs(root);
                cout << ans << endl;
            }
        }
        void dfs(int cur) {
            if (cur == erase) {
                return;
            }
            if (node[cur].size() == 0) {
                ans++;
                return;
            }
            for (auto next : node[cur]) {
                if (next == erase && node[cur].size() == 1) {
                    ans++;
                    continue;
                }
                dfs(next);
            }
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
