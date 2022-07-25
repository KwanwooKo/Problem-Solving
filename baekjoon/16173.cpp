#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define count _count
using namespace std;
typedef long long ll;
int map[4][4];
bool check[4][4];
int n;
int dx[] = {1, 0};
int dy[] = {0, 1};
bool dfs(int x, int y) {
    if (x == n && y == n) {
        return true;
    }
    int jump = map[x][y];
    bool flag = false;
    for (int k = 0; k < 2; k++) {
        int nx = x + jump * dx[k];
        int ny = y + jump * dy[k];
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (check[nx][ny]) continue;
        check[nx][ny] = true;
        flag = dfs(nx, ny);
        if (flag) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    bool flag = false;
    check[1][1] = true;
    flag = dfs(1, 1);
    if (flag) {
        cout << "HaruHaru" << endl;
    }
    else {
        cout << "Hing" << endl;
    }

    return 0;
}