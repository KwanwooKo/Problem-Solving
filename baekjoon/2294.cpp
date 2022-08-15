#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)10001
using namespace std;
typedef long long ll;
class BOJ2294 {
private:
    int n, m, ans;
    vector<int> d;
    int memo[10001];
public:
    BOJ2294() {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            d.push_back(num);
        }
        memo[0] = 0;
        for (int i = 1; i <= m; i++) {
            memo[i] = INF;
        }
        sort(d.begin(), d.end());
        ans = 0;
    }
    void solve() {
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < d.size(); j++) {
                if (i < d[j]) break;
                memo[i] = min(memo[i], memo[i - d[j]] + 1);
            }
        }
        print();
        // display();
    }
    void display() {
        for (int i = 0; i <= m; i++) {
            cout << memo[i] << ' ';
        }
        cout << endl;
    }
    void print() {
        if (memo[m] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << memo[m] << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2294 boj2294;
    boj2294.solve();
    return 0;
}