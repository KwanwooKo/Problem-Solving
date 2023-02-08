#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 987654321
using namespace std;

class Solution {
    private:
        int n, ans;
        int price[11];
        int prevPrice[11];
        bool check[11];
        int path[11];
        vector<pair<int, int> > discount[11];
    public:
        Solution() {
            ans = INF;
            cin >> n;
            for (int i = 1; i <= n; i++) {
                cin >> price[i];
                prevPrice[i] = price[i];
            }
            for (int i = 1; i <= n; i++) {
                int count;
                cin >> count;
                for (int j = 0; j < count; j++) {
                    int product, discountPrice;
                    cin >> product >> discountPrice;
                    discount[i].push_back(make_pair(product, discountPrice));
                }
            }
        }
        void go(int index) {
            if (index == n + 1) {
                int sum = 0;
                for (int x : path) {
                    sum += price[x];
                    for (auto &cur : discount[x]) {
                        int product = cur.first;
                        int discountPrice = cur.second;
                        price[product] = max(1, price[product] - discountPrice);
                    }
                }
                for (int i = 1; i <= n; i++) {
                    price[i] = prevPrice[i];
                }
                ans = min(ans, sum);
                return;
            }
            for (int i = 1; i <= n; i++) {
                if (check[i]) continue;
                check[i] = true;
                path[index] = i;
                go(index + 1);
                path[index] = 0;
                check[i] = false;
            }
        }
        void solve() {
            int index = 1;
            for (int i = 1; i <= n; i++) {
                check[i] = true;
                path[index] = i;
                go(index + 1);
                path[index] = 0;
                check[i] = false;
            }
            cout << ans << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
