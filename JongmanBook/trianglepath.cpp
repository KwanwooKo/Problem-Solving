#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int dx[] = {1, 1};
int dy[] = {0, 1};
class Solution {
    private:
        int n;
        int map[100][100];
        int cache[100][100];
    public:
        Solution() {
            memset(cache, 0, sizeof(cache));
            cin >> n;
            int count = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < count; j++) {
                    cin >> map[i][j];
                }
                count++;
            }
            cache[0][0] = map[0][0];
        }
        void printMap() {
            int count = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < count; j++) {
                    cout << map[i][j] << ' ';
                }
                count++;
                cout << endl;
            }
        }
        void printAns() {
            int ans = -1;
            for (int i = 0; i < n; i++) {
                ans = max(ans, cache[n-1][i]);
            }
            cout << ans << endl;
        }
        void go(int x, int y, int prev) {
            if (x == n) {
                return;
            }
            if (cache[x][y] <= map[x][y] + prev) {
                cache[x][y] = map[x][y] + prev;
            } else {
                return;
            }
            for (int k = 0; k < 2; k++) {
                go(x + dx[k], y + dy[k], cache[x][y]);
            }
        }
        void solve() {
            go(0, 0, 0);
            printAns();
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
