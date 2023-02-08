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
            if (index == m) {
                printList();
                return;
            }
            for (int i = cur; i < d.size(); i++) {
                list.push_back(d[i]);
                go(index + 1, i);
                list.pop_back();
            }
        }
        void solve() {
            go(0, 0);
        }

};
int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
    return 0;
}
