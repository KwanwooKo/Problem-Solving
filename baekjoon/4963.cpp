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
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
int n, m;
int map[51][51];
bool check[51][51];
void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (map[nx][ny] == 0) continue;
        if (check[nx][ny]) continue;
        check[nx][ny] = true;
        dfs(nx, ny);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> m >> n) {
        if (n == 0 && m == 0) {
            break;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (check[i][j]) continue;
                if (map[i][j] == 0) continue;
                check[i][j] = true;
                dfs(i, j);
                ans++;
            }
        }
        memset(map, 0, sizeof(map));
        memset(check, false, sizeof(check));
        cout << ans << endl;
    }
    return 0;
}