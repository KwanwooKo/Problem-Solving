#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
private:
    int n, m;
    bool areFriends[10][10];
public:
    Solution() {
        cin >> n >> m;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                areFriends[i][j] = false;
            }
        }
        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            areFriends[from][to] = true;
        }
    }
    int countPairings(bool taken[10]) {
        int firstFree = -1;
        for (int i = 0; i < n; i++) {
            if (taken[i] == false) {
                firstFree = i;
                break;
            }
        }
        if (firstFree == -1) return 1;

        int ret = 0;
        for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
            if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
                taken[firstFree] = true;
                taken[pairWith] = true;
                ret += countPairings(taken);
                taken[firstFree] = false;
                taken[pairWith] = false;
            }
        }
        return ret;
    }
    void solve() {
        bool taken[10];
        for (int i = 0; i < 10; i++) {
            taken[i] = false;
        }
        int ans = countPairings(taken);
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
}
