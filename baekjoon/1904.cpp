#include <iostream>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n;
        int cache[1000001];
    public:
        Solution() {
            cin >> n;
        }
        void solve() {
            const int mod = 15746;
            cache[1] = 1;
            cache[2] = 2;
            cache[3] = 3;
            for (int i = 4; i <= n; i++) {
                cache[i] = (cache[i - 1] % mod) + (cache[i - 2] % mod);
            }
            cout << cache[n] % mod << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
