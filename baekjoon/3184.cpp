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
int map[251][251];
bool check[251][251];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char num;
            cin >> num;
            if (num == '.') {
                continue;
            }
            // 벽
            if (num == '#') {
                map[i][j] = 3;
            }
            // 늑대
            if (num == 'v') {
                map[i][j] = 2;
            }
            // 양
            if (num == 'o') {
                map[i][j] = 1;
            }
        }
    }
    // 벽: 3, 늑대: 2, 양: 1
    vector<int> total_wolves;
    vector<int> total_sheep;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 3) continue;
            if (check[i][j]) continue;
            check[i][j] = true;
            queue<pair<int, int>> q;
            q.push({i, j});
            int wolves = 0;
            int sheep = 0;
            if (map[i][j] == 1) {
                sheep++;
            }
            if (map[i][j] == 2) {
                wolves++;
            }
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                    if (check[nx][ny]) continue;
                    check[nx][ny] = true;
                    if (map[nx][ny] == 3) continue;
                    // 양: 1
                    if (map[nx][ny] == 1) {
                        sheep++;
                    }
                    // 늑대: 2
                    if (map[nx][ny] == 2) {
                        wolves++;
                    }
                    q.push({nx, ny});
                }
            }
            if (wolves == 0 && sheep == 0) {
                continue;
            }
            if (wolves < sheep) {
                total_sheep.push_back(sheep);
            }
            else {
                total_wolves.push_back(wolves);
            }
        }
    }

    int ans_sheep = 0;
    int ans_wolves = 0;
    for (int i = 0; i < total_sheep.size(); i++) {
        ans_sheep += total_sheep[i];
    }
    for (int i = 0; i < total_wolves.size(); i++) {
        ans_wolves += total_wolves[i];
    }
    cout << ans_sheep << ' ' << ans_wolves << endl;
    return 0;
}