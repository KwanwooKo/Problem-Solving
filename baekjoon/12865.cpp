#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ12865 {
private:
    int n, k, ans;
    int weight[101];
    int price[101];
    int memo[100001][101];
public:
    BOJ12865() {
        cin >> n >> k;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            int w, p;
            cin >> w >> p;
            weight[i] = w;
            price[i] = p;
        }
        for (int i = 0; i <= 100000; i++) {
            for (int j = 0; j <= 100; j++) {
                memo[i][j] = 0;
            }
        }
    }
    void solve() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j >= weight[i]) {
                    memo[j][i] = max(memo[j][i - 1], memo[j - weight[i]][i - 1] + price[i]);
                }
                else {
                    memo[j][i] = memo[j][i - 1];
                }
            }
        }
        print();
    }
    void print() {
        for (int i = 0; i <= n; i++) {
            ans = max(ans, memo[k][i]);
        }
        cout << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ12865 boj12865;
    boj12865.solve();
    return 0;
}