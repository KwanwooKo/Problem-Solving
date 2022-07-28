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
bool check[200][200];
int map[200][200];
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int n, r1, c1, r2, c2, ans = -1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    check[r1][c1] = true;
    queue<pair<int, int>> q;
    q.push({r1, c1});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 6; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (check[nx][ny]) continue;
            check[nx][ny] = true;
            map[nx][ny] = map[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if (map[r2][c2]) {
        cout << map[r2][c2] << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}