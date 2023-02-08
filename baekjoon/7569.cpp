#include <iostream>
#include <tuple>
#include <cstring>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
class Solution {
    private:
        int n, m, h;
        int map[101][101][101];
        bool check[101][101][101];
        int ans[101][101][101];
        queue<tuple<int, int, int> > q;
    public:
        Solution() {
            cin >> m >> n >> h;
            memset(ans, 0, sizeof(ans));
            memset(map, 0, sizeof(map));
            memset(check, false, sizeof(check));
            for (int k = 1; k <= h; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        cin >> map[i][j][h];
                        if (map[i][j][h] == 1) {
                            ans[i][j][k] = 0;
                            q.push({i, j, k});
                        }
                    }
                }
            }
        }
        void printAns() {
            int cmp = 0;
            for (int k = 1; k <= h; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (ans[i][j][k] == -1) {
                            cout << "-1" << endl;
                            return;
                        }
                        cmp = max(cmp, ans[i][j][k]);
                    }
                }
            }
            cout << ans << endl;
        }
        void bfs() {
            while (!q.empty()) {
                int x = get<0>(q.front());
                int y = get<1>(q.front());
                int z = get<2>(q.front());
                q.pop();
                for (int k = 0; k < 6; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    int nz = z + dz[k];
                    // 맵을 벗어나는 경우
                    if (nx < 1 || ny < 1 || nz < 1 || nx > n || ny > m || nz > h) continue;
                    // 이미 방문한 경우
                    if (check[nx][ny][nz]) continue;
                    if (map[nx][ny][nz] == -1) continue;
                    check[nx][ny][nz] = true;
                    q.push({nx, ny, nz});
                }
            }

        }
        void solve() {
            bfs();
            printAns();
        }

};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
