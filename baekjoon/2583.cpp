#include <iostream>
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
    int n , m , k;
    cin >> n >> m >> k;                     // 5 7
    while (k--) {
        // 행렬로 보지 말고 좌표로 보자
        int mx, my, Mx, My;                 // y 좌표가 행이랑 관련 있음
        cin >> my >> mx >> My >> Mx;        // (0, 2) => (0, 3)
        for (int i = mx; i < Mx; i++) {
            for (int j = my; j < My; j++) {
                map[i][j] = 1;
            }
        }

    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << map[i][j] << ' ';
//        }
//        cout << endl;
//    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] || map[i][j] == 1) continue;
            int count = 0;
            queue<pair<int, int> > q;
            q.push(make_pair(i, j));
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (check[nx][ny] || map[nx][ny] == 1) continue;
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                    count++;
                }
            }
            if (count == 0) count++;
            ans.push_back(count);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}