#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

class Solution {
public:
    explicit Solution(vector<int>& d) : clocks(d) {}

    void printClocks() {
        for (int clock : clocks) {
            cout << clock << ' ';
        }
        cout << '\n';
    }
    void printSwtch() {
        for (auto cur : swtch) {
            for (int num : cur) {
                cout << num << ' ';
            }
            cout << '\n';
        }
    }

    bool isAllClockTwelve() {
        for (int clock : clocks) {
            if (clock != 12) return false;
        }
        return true;
    }

    void clickSwtch(int idx) {
        for (int i : swtch[idx]) {
            if (clocks[i] == 12) clocks[i] = 3;
            else clocks[i] += 3;
        }
    }

    void go(int idx) {
        // 기저 조건: 모든 시계가 12시 방향
        if (isAllClockTwelve()) {
            ans = min(ans, count);
            return;
        }
        // 기저 조건: 10번째 시계가 없음
        if (idx == 10) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            go(idx + 1);
            clickSwtch(idx);
            count++;
        }
        count -= 4;
    }

    void solve() {
        go(0);
        if (ans == INF) cout << -1 << '\n';
        else cout << ans << '\n';
    }

private:
    int count = 0;
    int ans = INF;
    const vector<int> swtch[10] = {
        {0, 1, 2}, 
        {3, 7, 9, 11},
        {4, 10, 14, 15},
        {0, 4, 5, 6, 7},
        {6, 7, 8, 10, 12},
        {0, 2, 14, 15},
        {3, 14, 15},
        {4, 5, 7, 14, 15},
        {1, 2, 3, 4, 5},
        {3, 4, 5, 9, 13}
    };
    vector<int> clocks;
    vector<int> operator=(vector<int>& d) {
        for (int v : d) {
            this->clocks.push_back(v);
        }
        return this->clocks;
    }
};


int main(void) {
    int t;
    cin >> t;
    while (t--) {
        vector<int> d(16);
        for (int i = 0; i < 16; i++) {
            cin >> d[i];
        }
        Solution sol(d);
        sol.solve();
    }
    return 0;
}