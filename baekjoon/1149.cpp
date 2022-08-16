#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ1149 {
private:
    int n, ans;
    int house[1001][3]; // 0: R, 1: G, 2: B
    int memo[1001][3];
public:
    BOJ1149() {
        cin >> n;
        ans = INF;
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j < 3; j++) {
                house[i][j] = 0;
                memo[i][j] = INF;       
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> house[i][0];
            cin >> house[i][1];
            cin >> house[i][2];
        }
        memo[1][0] = house[1][0];
        memo[1][1] = house[1][1];
        memo[1][2] = house[1][2];
    }
    void solve() {
        for (int i = 2; i <= n; i++) {
            memo[i][0] = min(memo[i][0], 
                         min(memo[i - 1][1] + house[i][0], 
                            memo[i - 1][2] + house[i][0]));
            memo[i][1] = min(memo[i][1], 
                         min(memo[i - 1][0] + house[i][1], 
                            memo[i - 1][2] + house[i][1]));
            memo[i][2] = min(memo[i][2], 
                         min(memo[i - 1][0] + house[i][2], 
                            memo[i - 1][1] + house[i][2]));
        }
        // display();
        print();
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                cout << memo[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    void print() {
        for (int i = 0; i < 3; i++) {
            ans = min(ans, memo[n][i]);
        }
        cout << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ1149 boj1149;
    boj1149.solve();
    return 0;
}