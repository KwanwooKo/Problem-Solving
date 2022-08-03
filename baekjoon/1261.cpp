#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check[101][101];
int map[101][101];
int break_wall[101][101];
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %1d", &map[i][j]);
            break_wall[i][j] = INF;
        }
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 1, 1});
    break_wall[1][1] = 0;
    check[1][1] = true;
    while (!pq.empty()) {
        int price = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();
//        cout << "현재 노드: " << x << " " << y << endl;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                cout << break_wall[i][j] << ' ';
//            }
//            cout << endl;
//        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (map[nx][ny] == 1) {
                if (check[nx][ny]) continue;
                check[nx][ny] = true;
                if (price + 1 <= break_wall[nx][ny]) {
                    pq.push({price + 1, nx, ny});
                    break_wall[nx][ny] = price + 1;
                }

            }
            else if (map[nx][ny] == 0) {
                if (check[nx][ny]) continue;
                check[nx][ny] = true;
                if (price <= break_wall[nx][ny]) {
                    pq.push({price, nx, ny});
                    break_wall[nx][ny] = price;
                }
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (break_wall[i][j] == INF) {
//                cout << "INF ";
//            }
//            else {
//                cout << break_wall[i][j] << ' ';
//            }
//        }
//        cout << endl;
//    }
    if (break_wall[n][m] == INF) {
        cout << 0 << endl;
    }
    else {
        cout << break_wall[n][m] << endl;
    }
    return 0;
}