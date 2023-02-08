#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
private:
    bool check[10001];
public:
    Solution() {
        for (int i = 1; i <= 10000; i++) {
            check[i] = false;
        }
    }
    int addAllNum(int num) {
        int ret = 0;
        ret += num;
        while (num != 0) {
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }
    void printSelfNum() {
        for (int i = 1; i <= 10000; i++) {
            if (check[i]) continue;
            cout << i << endl;
        }
    }
    void checkAllNum(int num) {
        int checkNum = num;
        while (1) {
            if (checkNum > 10000) break;
            checkNum = addAllNum(checkNum);
            check[checkNum] = true;
        }
    }
    void solve() {
        for (int i = 1; i <= 10000; i++) {
            if (check[i]) continue;
            checkAllNum(i);
        }
        printSelfNum();
    }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
