#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int map[301][301];
int tmp_map[301][301];
bool check[301][301];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    int t = 0;
    while (1) {
        int place = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (check[i][j]) continue;
                check[i][j] = true;
                if (map[i][j] == 0) continue;
                place++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    int count = 0;      // 사방에 0 인 지점이 몇개인지
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                        if (map[nx][ny] == 0) count++;  // 주변에 물이 있는지 먼저 체크하고
                        if (check[nx][ny]) continue;    // 그 위치가 방문했던 위치면 넘어가기
                        check[nx][ny] = true;
                        if (map[nx][ny] != 0) {
                            q.push({nx, ny});
                        }
                    }
                    tmp_map[x][y] = map[x][y] - count;
                    if (tmp_map[x][y] < 0) tmp_map[x][y] = 0;
                }
            }
        }
        t++;
        if (place >= 2) {
            ans = t - 1;
            break;
        }
        if (place == 0) {
            ans = 0;
            break;
        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                cout << map[i][j] << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                map[i][j] = tmp_map[i][j];
                tmp_map[i][j] = 0;
                check[i][j] = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}