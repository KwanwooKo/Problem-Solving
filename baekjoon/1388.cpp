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
int **map;
bool **check;
int d1x[] = {0, 0};
int d1y[] = {1, -1};
int d2x[] = {1, -1};
int d2y[] = {0, 0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    map = (int**)malloc(sizeof(int*) * (n + 1));
    check = (bool**)malloc(sizeof(bool*) * (n + 1));
    for (int i = 0; i <= n; i++) {
        map[i] = (int*)malloc(sizeof(int) * (m + 1));
        check[i] = (bool*)malloc(sizeof(bool) * (m + 1));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '-') {
                map[i][j] = 0;
            }
            if (c == '|') {
                map[i][j] = 1;
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << map[i][j] << ' ';
//        }
//        cout << endl;
//    }
    // - 확인
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j]) continue;
            if (map[i][j]) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            check[i][j] = true;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 2; k++) {
                    int nx = x + d1x[k];
                    int ny = y + d1y[k];
                    if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                    if (check[nx][ny]) continue;
                    if (map[nx][ny]) continue;
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            ans++;
        }
    }
    // | 확인
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j]) continue;
            if (!map[i][j]) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            check[i][j] = true;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 2; k++) {
                    int nx = x + d2x[k];
                    int ny = y + d2y[k];
                    if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                    if (check[nx][ny]) continue;
                    if (!map[nx][ny]) continue;
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
    free(map);
    return 0;
}