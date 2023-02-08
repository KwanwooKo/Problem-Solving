#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
class Solution {
    private:
        int n, m;
        vector<int> d;
        vector<int> list;
        bool check[9];
    public:
        Solution() {
            cin >> n >> m;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                d.push_back(num);
                check[i] = false;
            }
            sort(d.begin(), d.end());
        }
        void printList() {
            for (int i = 0; i < list.size(); i++) {
                cout << list[i] << ' ';
            }
            cout << endl;
        }
        void go(int index, int cur) {
            // 기저 조건
            if (index == m) {
                printList();
                return;
            }
            int last = -1;
            for (int i = cur; i < d.size(); i++) {
                if (check[i]) continue;
                if (d[i] == last) {
                    continue;
                }
                check[i] = true;
                list.push_back(d[i]);
                last = d[i];
                go(index + 1, i + 1);
                check[i] = false;
                list.pop_back();
            }
        }
        void solve() {
            // 중복 수열 체크를 어떻게 하지?
            go(0, 0);
        }

};
int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
    return 0;
}

