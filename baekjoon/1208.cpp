#include <iostream>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n, s;
        vector<int> arr;
    public:
        Solution() {
            cin >> n >> s;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                arr.push_back(num);
            }
        }
        void solve() {

        }
};


int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
