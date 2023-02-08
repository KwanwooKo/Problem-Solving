#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 987654321
using namespace std;

class Solution {
    private:
        int clock[16];
        int ans;
        int clicked;
        vector<int> button[10];
    public:
        Solution() {
            ans = INF;
            clicked = 0;
            for (int i = 0; i < 16; i++) {
                cin >> clock[i];
            }
            // 0 1 2
            button[0].push_back(0);
            button[0].push_back(1);
            button[0].push_back(2);
            // 3 7 9 11
            button[1].push_back(3);
            button[1].push_back(7);
            button[1].push_back(9);
            button[1].push_back(11);
            // 4 10 14 15
            button[2].push_back(4);
            button[2].push_back(10);
            button[2].push_back(14);
            button[2].push_back(15);
            // 0 4 5 6 7
            button[3].push_back(0);
            button[3].push_back(4);
            button[3].push_back(5);
            button[3].push_back(6);
            button[3].push_back(7);
            // 6 7 8 10 12
            button[4].push_back(6);
            button[4].push_back(7);
            button[4].push_back(8);
            button[4].push_back(10);
            button[4].push_back(12);
            // 0 2 14 15
            button[5].push_back(0);
            button[5].push_back(2);
            button[5].push_back(14);
            button[5].push_back(15);
            // 3 14 15
            button[6].push_back(3);
            button[6].push_back(14);
            button[6].push_back(15);
            // 4 5 7 14 15
            button[7].push_back(4);
            button[7].push_back(5);
            button[7].push_back(7);
            button[7].push_back(14);
            button[7].push_back(15);
            // 1 2 3 4 5
            button[8].push_back(1);
            button[8].push_back(2);
            button[8].push_back(3);
            button[8].push_back(4);
            button[8].push_back(5);
            // 3 4 5 9 13
            button[9].push_back(3);
            button[9].push_back(4);
            button[9].push_back(5);
            button[9].push_back(9);
            button[9].push_back(13);
        }
        bool checkAllClocks() {
            for (int i = 0; i < 16; i++) {
                if (clock[i] != 12) {
                    return false;
                }
            }
            return true;
        }
        void clickButton(int type) {
            for (unsigned int i = 0; i < button[type].size(); i++) {
                clock[button[type][i]] += 3;
                if (clock[button[type][i]] > 12) {
                    clock[button[type][i]] %= 12;
                }
            }
        }
        int go(int type) {
            if (type == 10) {
                return checkAllClocks() ? 0 : INF;
            }
            int ret = INF;
            for (int i = 0; i < 4; i++) {
                ret = min(ret, i + go(type + 1));
                clickButton(type);
            }
            return ret;
        }
        void solve() {
            ans = go(0);
            ans = ans == INF ? -1 : ans;
            cout << ans << endl;
        }
};

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        Solution* sol = new Solution();
        sol->solve();
        delete sol;
    }
    return 0;
}
