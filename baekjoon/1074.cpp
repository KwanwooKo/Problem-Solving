#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n, r, c, ans;
    public:
        Solution() {
            cin >> n >> r >> c;
            ans = -1;
        }
        void go(int x, int y, int size, int add, int count) {
            if (size == 1) {
                if (x == r && y == c) {
                    ans = count;
                }
                return;
            }
            if (x + size / 2 <= r && y + size / 2 <= c) {
                go(x + size / 2, y + size / 2, size / 2, add / 4, count + add * 3);
            }
            else if (x + size / 2 <= r && y + size / 2 > c) {
                go(x + size / 2, y, size / 2, add / 4, count + add * 2);
            }
            else if (x + size / 2 > r && y + size / 2 <= c) {
                go(x, y + size / 2, size / 2, add / 4, count + add * 1);
            } 
            else if (x + size / 2 > r && y + size / 2 > c) {
                go(x, y, size / 2, add / 4, count + add * 0);
            }
        }
        int pow(int n) {
            int ret = 1;
            while (n--) {
                ret *= 2;
            }
            return ret;
        }
        void solve() {
            int size = pow(n);
            go(0, 0, size, size * size / 4, 0);
            cout << ans << endl;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
