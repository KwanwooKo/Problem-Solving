#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

int map[101][101];                 // 잠기면 true, 안 잠기면 false
bool check[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
// vector<int> ans;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ans = -1;
    int n;
    cin >> n;
    int max = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (max < map[i][j]) {
                max = map[i][j];
            }
        }
    }
    int start = 0;
    
    while (1) {
        int count = 0;
        if (start > max - 1) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                check[i][j] = false;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (map[i][j] <= start) continue;  // 잠겨 있으면 넘어가고
                if (check[i][j]) continue;        // 이미 방문했으면 넘어가고

                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                count++;
                check[i][j] = true;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                        if (check[nx][ny]) continue;

                        if (map[nx][ny] > start) {
                            q.push(make_pair(nx, ny));
                            check[nx][ny] = true;
                        }
                    }
                    
                }   
                
            }
        }
        
        if (ans < count) {
            ans = count;
        }
        start++;
    }

    cout << ans << endl;
    return 0;

}


