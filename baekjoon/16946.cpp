#include <iostream>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
#define endl '\n'
#define MAX 1001
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int map[MAX][MAX];
bool check[MAX][MAX];
int group[MAX][MAX];
int ans[MAX][MAX];
int components[MAX * MAX];
class Solution {
    private:
        int n, m;
    public:
        Solution() {
            cin >> n >> m;
            for (int i = 1; i <= n; i++) {
                string s;
                cin >> s;
                for (int j = 1; j <= m; j++) {
                    map[i][j] = s[j - 1] - '0';
                }
            }
        }
        void findGroup() {
            queue<pair<int, int>> q;
            int num = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (map[i][j] == 1) continue;
                    if (check[i][j]) continue;
                    int count = 1;
                    q.push({i, j});
                    check[i][j] = true;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        group[x][y] = num;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                            if (map[nx][ny]) continue;
                            if (check[nx][ny]) continue;
                            check[nx][ny] = true;
                            q.push({nx, ny});
                            count++;
                        }
                    }
                    components[num++] = count;
                }
            }
        }
        void findAns() {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (map[i][j] == 0) continue;
                    int num = 1;
                    set<int> duplicates;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 1 || y < 1 || x > n || y > m) continue;
                        if (duplicates.find(group[x][y]) != duplicates.end()) continue;
                        if (map[x][y]) continue;
                        int groupNum = group[x][y];
                        duplicates.insert(groupNum);
                        num += components[groupNum];
                        num %= 10;
                    }
                    ans[i][j] = num % 10;
                }
            }
        }
        void printGroup() {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cout << group[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        void printAns() {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }
        void solve() {
            findGroup();
            findAns();
            printAns();
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Solution sol;
    sol.solve();
    return 0;
}
