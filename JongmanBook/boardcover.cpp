#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n, m, ans;
        int map[21][21];
        int block[4][2][2] = {
            { {0, 1}, {1, 0} },
            { {0, 1}, {1, 1} },
            { {1, 0}, {1, 1} },
            { {1, 0}, {1, -1} }
        };
    public:
        Solution() {
            cin >> n >> m;
            ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    char c;
                    cin >> c;
                    if (c == '.') map[i][j] = 0;
                    else if (c == '#') map[i][j] = 1;
                }
            }
        }
        void printMap() {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (map[i][j] == 0) cout << '.';
                    else if (map[i][j] == 1) cout << '#';
                    else cout << 'B';
                }
                cout << endl;
            }
            cout << endl;
        }
        int cover() {
            int x = -1, y = -1, ret = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (map[i][j] == 0) {
                        x = i, y = j;
                        break;
                    }
                }
                if (y != - 1) break;
            }
            if (y == -1) return 1;

            for (int k = 0; k < 4; k++) {
                int x1 = x + block[k][0][0];
                int y1 = y + block[k][0][1];
                int x2 = x + block[k][1][0];
                int y2 = y + block[k][1][1];
                // 블록이 map 을 벗어나는지 확인
                if (x1 < 1 || y1 < 1 || x1 > n || y1 > m) continue;
                if (x2 < 1 || y2 < 1 || x2 > n || y2 > m) continue;
                // 다른 블록이랑 겹치는지 or # 인지 확인
                if (map[x1][y1] == 1 || map[x1][y1] == 2) continue;
                if (map[x2][y2] == 1 || map[x2][y2] == 2) continue;
                // map[x][y] = 2 로 설정
                map[x][y] = 2;
                map[x1][y1] = 2;
                map[x2][y2] = 2;
                // printMap();
                ret += cover();
                map[x][y] = 0;
                map[x1][y1] = 0;
                map[x2][y2] = 0;
            }

            return ret;
        }
        void solve() {
            ans += cover();
            // printMap();
            cout << ans << endl;
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
