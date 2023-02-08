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
                check[num] = false;
            }
            sort(d.begin(), d.end());
        }
        void printList() {
            for (int i = 0; i < list.size(); i++) {
                cout << list[i] << ' ';
            }
            cout << endl;
        }
        void go(int index) {
            // 기저조건
            if (index == m) {
                printList();
                return;
            }
            for (int i = 0; i < d.size(); i++) {
                if (check[i]) continue;
                check[i] = true;
                list.push_back(d[i]);
                go(index + 1);
                list.pop_back();
                check[i] = false;
            }
        }
        void solve() {
            go(0);
        }

};
int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
    return 0;
}
