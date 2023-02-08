#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 987654321
using namespace std;

class Solution {
    private:
        int n, ans, total;
        int map[21][21];
        bool check[21];
        vector<int> team;
    public:
        Solution() {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cin >> map[i][j];
                    total += map[i][j];
                }
            }
            ans = INF;
        }
        void printTeam(vector<int>& tmp) {
            for (int i = 1; i <= tmp.size(); i++) {
                cout << tmp[i] << ' ';
            }
            cout << endl;
        }
        int getSum(vector<int>& tmp) {
            int ret = 0;
            for (int i = 0; i < tmp.size(); i++) {
                for (int j = i; j < tmp.size(); j++) {
                    int a = tmp[i], b = tmp[j];
                    ret += map[a][b];
                    ret += map[b][a];
                }
            }
            return ret;
        }
        void go(int cur, int index) {
            if (index == n / 2) {
                vector<int> team2;
                for (int i = 1; i <= n; i++) {
                    if (check[i]) continue;
                    team2.push_back(i);
                }
                int sum1 = getSum(team);
                int sum2 = getSum(team2);
                ans = min(ans, abs(sum1 - sum2));
                return;
            }
            for (int i = cur; i <= n; i++) {
                if (check[i]) continue;
                check[i] = true;
                team.push_back(i);
                go(i, index + 1);
                check[i] = false;
                team.pop_back();
            }
        }
        void solve() {
            for (int i = 1; i <= n; i++) {
                check[i] = true;
                team.push_back(i);
                go(1, 1);
                check[i] = false;
                team.pop_back();
            }
            cout << ans << endl;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
    return 0;
}
