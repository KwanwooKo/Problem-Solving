#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <vector>
#define endl '\n'
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int map[50][50];
        bool check[50][50];
        vector<int> depth;
        int ans = 0;
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                check[i][j] = false;
                map[i][j] = 0;
            }
        }
        queue<pair<int, int> > q;
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            map[a][b] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1 && !check[i][j]) {
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if (!check[nx][ny] && map[nx][ny] == 1) {
                                q.push(make_pair(nx, ny));
                                check[nx][ny] = true;
                            }
                        }
                    }
                    ans++;
                }

            }
        }


        cout << ans << endl;


    }
    return 0;
}
