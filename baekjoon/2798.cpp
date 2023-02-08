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
    int n, m;
    int minDiff = INF;
    int ans;
    vector<int> d;
public:
    Solution() {
        cin >> n >> m;
        ans = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            d.push_back(num);
        }
    }
    void solve() {
        for (int i = 0; i < d.size(); i++) {
            for (int j = i + 1; j < d.size(); j++) {
                for (int k = j + 1; k < d.size(); k++) {
                    int sum = d[i] + d[j] + d[k];
                    if (sum > m) continue;
                    if (m - sum < minDiff) {
                        minDiff = abs(sum - m);
                        ans = sum;
                    }
                }
            }
        }
        cout << ans << endl;
    }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
