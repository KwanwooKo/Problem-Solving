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
int map[101][101];
bool check[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> m >> n;
    int white_power = 0, black_power = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'B') {
                map[i][j] = 1;
            }
        }
    }

    // W: 0, B: 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j]) continue;
            check[i][j] = true;
            int white = 0, black = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            if (map[i][j] == 0) white++;
            if (map[i][j] == 1) black++;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                    if (check[nx][ny]) continue;
                    if (map[nx][ny] != map[x][y]) continue;
                    check[nx][ny] = true;
                    if (map[nx][ny] == 0) white++;
                    if (map[nx][ny] == 1) black++;
                    q.push({nx, ny});
                }
            }

            if (map[i][j] == 0) white_power += white * white;
            if (map[i][j] == 1) black_power += black * black;
        }
    }
    cout << white_power << ' ' << black_power << endl;
    return 0;
}