#include <iostream>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int piece[6];
        int arr[6];
    public:
        Solution() {
            piece[0] = 1;
            piece[1] = 1;
            piece[2] = 2;
            piece[3] = 2;
            piece[4] = 2;
            piece[5] = 8;
            for (int i = 0; i < 6; i++) {
                cin >> arr[i];
            }
        }
        void solve() {
            for (int i = 0; i < 6; i++) {
                cout << piece[i] - arr[i] << ' ';
            }
            cout << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
