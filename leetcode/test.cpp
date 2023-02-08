#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        for (int i = 0; i < strs.size(); i++) {
            cout << strs[i] << endl;
        }
    }
    void solve() {
        vector<string> strs;
        string s;
        cout << "문자열 입력: ";
        cin >> s;
        strs.push_back(s);
        minDeletionSize(strs);
    }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
