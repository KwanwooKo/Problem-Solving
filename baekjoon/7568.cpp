#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define endl '\n'
#define INF 987654321
using namespace std;

class Solution {
    private:
        int n;
        vector<pair<int, int> > list;
        int ans[51];
    public:
        Solution() {
            cin >> n;
            for (int i = 0; i < n; i++) {
                int height, weight;
                cin >> weight >> height;
                list.push_back(make_pair(weight, height));
            }
        }
        void printAns() {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        void solve() {
            for (int i = 0; i < n; i++) {
                int rank = 1;
                int curWeight = list[i].first;
                int curHeight = list[i].second;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    int cmpWeight = list[j].first;
                    int cmpHeight = list[j].second;
                    if (curWeight < cmpWeight && curHeight < cmpHeight) {
                        rank++;
                    }
                }
                ans[i] = rank;
            }
            printAns();
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
