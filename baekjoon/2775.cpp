#include <iostream>
#include <cstring>
using namespace std;

class Solution {
    private:
        int k, n;
        int cache[15][15];
        int map[15][15];
    public:
        Solution() {
            memset(cache, 0, sizeof(cache));
            memset(map, 0, sizeof(map));
            for (int i = 1; i <= 14; i++) {
                map[0][i] = i;
                cache[0][i] = i;
            }
            for (int i = 1; i <= 14; i++) {
                for (int j = 1; j <= 14; j++) {
                    cache[i][j] = cache[i][j-1] + cache[i-1][j];
                }
            }
        }
        void printCache() {
            for (int i = 0; i <= 14; i++) {
                for (int j = 0; j <= 14; j++) {
                    cout << cache[i][j] << ' ';
                }
                cout << endl;
            }
        }
        void solve() {
            cin >> k >> n;
            cout << cache[k][n] << endl;
        }
};

int main(void) {
    int t;
    cin >> t;
    Solution* sol = new Solution();
    while (t--) {
        sol->solve();
    }
    delete sol;
}
