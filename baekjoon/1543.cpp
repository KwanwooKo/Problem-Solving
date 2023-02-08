#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

class Solution {
    private:
        string a, b;
        int ans;
    public:
        Solution() {
            getline(cin, a);
            getline(cin, b);
            ans = 0;
        }
        void solve() {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == b[0]) {
                    if (a.substr(i, b.size()) == b) {
                        i += (b.size() - 1);
                        ans++;
                    }
                }
            }
            cout << ans << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
