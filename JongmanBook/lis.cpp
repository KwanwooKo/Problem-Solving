#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n, ans;   
        int arr[501];
        int cache[501];
    public:
        Solution() {
            memset(arr, 0, sizeof(arr));
            memset(cache, 0, sizeof(cache));
            ans = 0;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        }
        void printAns() {
            for (int i = 0; i < n; i++) {
                ans = max(ans, cache[i]);
            }
            cout << ans + 1 << endl;
        }
        void printCache() {
            cout << endl;
            cout << "==========print cache==========" << endl;
            for (int i = 0; i < n; i++) {
                cout << cache[i] << ' ';
            }
            cout << endl;
        }
        void solve() {
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (arr[i] < arr[j]) {
                        cache[j] = max(cache[j], cache[i] + 1);
                    }
                }
            }
            //printCache();
            printAns();
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
}
