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
int map[26][26];
int check[26][26];
int count = 1;
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y) {
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (check[nx][ny]) continue;
        if (!map[nx][ny]) continue;
        check[nx][ny] = true;
        count++;
        dfs(nx, ny);
    }
}
int main() {
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %1d", &map[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (check[i][j]) continue;
            if (!map[i][j]) continue;
            check[i][j] = true;
            dfs(i, j);
            ans.push_back(count);
            count = 1;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}