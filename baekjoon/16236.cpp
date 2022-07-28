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
int map[21][21];
bool check[21][21] = {false, };
int road[21][21] = {0, };
int dx[] = {-1, 0, 1,0};
int dy[] = {0, -1, 0, 1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, time = 0;
    cin >> n;
    int fish_x = 0, fish_y = 0, fish_count = 0;
    vector<tuple<int, int, int>> fish_list;
    int fish_size = 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                fish_x = i;
                fish_y = j;
                map[i][j] = 0;
            }
        }
    }
    // 물고기 지나간 자리는 0으로
    while (1) {
        memset(check, false, sizeof(check));
        memset(road, 0, sizeof(road));
//        // 지도 출력
//        cout << "지도출력" << endl;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                cout << map[i][j] << ' ';
//            }
//            cout << endl;
//        }
        queue<pair<int, int>> q;
        q.push({fish_x, fish_y});
        check[fish_x][fish_y] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
//            cout << x << ' ' << y << " 거리: " << road[x][y] << endl;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                if (check[nx][ny]) continue;
                check[nx][ny] = true;
                // 물고기를 잡아먹는 경우
                if (map[nx][ny] < fish_size && map[nx][ny]) {
                    road[nx][ny] = road[x][y] + 1;
                    fish_list.push_back({road[nx][ny], nx, ny});
                }
                else if (map[nx][ny] > fish_size) {
                    continue;
                }
                road[nx][ny] = road[x][y] + 1;
                q.push({nx, ny});
            }
        }
        if (fish_list.empty()) {
            break;
        }
        sort(fish_list.begin(), fish_list.end());
        int dist = get<0>(fish_list[0]);
        fish_x = get<1>(fish_list[0]);
        fish_y = get<2>(fish_list[0]);
        map[fish_x][fish_y] = 0;
        fish_list.clear();
//        cout << "현재 위치: " << fish_x << ' ' << fish_y << " 지금까지 걸린시간: ";
        time += dist;   // 시간 추가
        if (fish_size >= 7) continue;
        fish_count++;   // 먹은 물고기 수 추가
        if (fish_size == fish_count) {
            fish_size++;
            fish_count = 0;
        }
//        cout << time << endl;
    }
    cout << time << endl;
//    cout << fish_x << ' ' << fish_y << endl;
    return 0;
}