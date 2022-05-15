#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
int map[101][101];
bool check[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        map[row][col] = 1;
    }
    vector<int> ans;
    queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int count = 0;
            if (check[i][j] || map[i][j] == 0) continue;
            q.push(make_pair(i, j));
            check[i][j] = true;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                    if (check[nx][ny] || map[nx][ny] == 0) continue;
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                }
                count++;
            }
            ans.push_back(count);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] << endl;
    return 0;
}


