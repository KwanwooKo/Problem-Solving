#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
#define endl '\n'
using namespace std;

class Solution {
    private:
        int visited[100001];
        int ans[100001];
        int n, m;
        queue<int> q;
    public:
        Solution() {
            cin >> n >> m;
            for (int i = 0; i <= 100000; i++) {
                visited[i] = INF;
            }
            visited[n] = 0;
            if (n == m) {
                ans[n] = 1;
            }
            q.push(n);
        }
        void bfs() {
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                int& count = visited[x];
                // map 을 벗어나는 경우 방지
                if (x * 2 <= 100000) {
                    // visited 회수가 더 작은 걸로 갱신될 때
                    if (count + 1 <= visited[2 * x]) {
                        visited[2 * x] = count + 1;
                        ans[2 * x]++;
                        q.push(2 * x);
                    }
                }
                if (x + 1 <= 100000) {
                    if (count + 1 <= visited[x + 1]) {
                        visited[x + 1] = count + 1;
                        ans[x + 1]++;
                        q.push(x + 1);
                    }
                }
                if (x - 1 >= 0) {
                    if (count + 1 <= visited[x - 1]) {
                        visited[x - 1] = count + 1;
                        ans[x - 1]++;
                        q.push(x - 1);
                    }
                }
            }
        }
        void printAns() {
            cout << visited[m] << endl;
            cout << ans[m] << endl;
        }
        void solve() {
            bfs();
            printAns();
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
    return 0;
}
