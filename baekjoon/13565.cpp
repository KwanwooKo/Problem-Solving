#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int map[1001][1001];
bool check[1001][1001];
int main(void) {
    int row, col;
    cin >> row >> col;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    
    for (int j = 1; j <= col; j++) {
        if (map[1][j] == 1) continue;

        queue<pair<int, int>> q;
        q.push(make_pair(1, j));

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx == row) {
                    cout << "YES" << endl;
                    return 0;
                }
                if (nx < 1 || ny < 1 || nx > row || ny > col) continue;
                if (check[nx][ny] || map[nx][ny] == 1) continue;
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    cout << "NO" << endl;
    return 0;

}


