#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

class Solution {
    private:
        vector<string> tmp;
        vector<int> delList;
    public:
        int minDeletionSize(vector<string>& strs) {
            int len = strs[0].size();
            char cmp;
            // column 비교
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < strs.size(); j++) {
                    if (j == 0) cmp = strs[j][i];
                    else {
                        if (strs[j][i] < cmp) {
                            delList.push_back(i);
                            break;
                        } else {
                            cmp = strs[j][i];
                        }
                    }
                }
            }

            return delList.size();
        }
        void solve() {
            for (int i = 0; i < 3; i++) {
                string s;
                cin >> s;
                tmp.push_back(s);
            }
            minDeletionSize(tmp);
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
