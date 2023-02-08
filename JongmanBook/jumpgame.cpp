#include <iostream>
#define endl '\n'
#define ARRIVE 1
#define NOTARRIVE -1
#define NOTVISITED 0
using namespace std;


class Solution {
    private:
        int map[101][101];
        int n;
        int check[101][101];
    public:
        Solution() {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cin >> map[i][j];
                    check[i][j] = NOTVISITED;
                }
            }
        }
        bool go(int x, int y) {
            bool ret = false;
            // 기저 조건
            if (x == n && y == n) {
                return true;
            }
            if (check[x][y] == ARRIVE) {
                return true;
            } else if (check[x][y] == NOTARRIVE) {
                return false;
            }
            if (x + map[x][y] <= n) ret = go(x + map[x][y], y);
            if (y + map[x][y] <= n) ret = (ret || go(x, y + map[x][y]));

            if (ret) check[x][y] = ARRIVE;
            else check[x][y] = NOTARRIVE;

            return ret; 
        }
        void solve() {
            bool ans = go(1, 1);
            if (ans) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

};

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        Solution* sol = new Solution();
        sol->solve();
        delete sol;
    }
}
