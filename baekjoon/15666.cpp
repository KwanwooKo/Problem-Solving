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
    public:
        Solution() {
            cin >> n >> m;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                d.push_back(num);
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
                if (d[i] == last) {
                    continue;
                }
                list.push_back(d[i]);
                last = d[i];
                go(index + 1, i);
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


