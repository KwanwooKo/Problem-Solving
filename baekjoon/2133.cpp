#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ2133 {
private:
    int n;
    int memo[31];
public:
    BOJ2133() {
        cin >> n;
        for (int i = 0; i <= 30; i++) {
            memo[i] = 0;
        }
        memo[2] = 3;
        memo[4] = 11;

    }
    void solve() {
        int count = 2;
        for (int i = 6; i <= n; i += 2) {
            memo[i] = memo[i - 2] * memo[2] + 2;
            // memo[i] = memo[i - 2] * memo[2] + memo[i - 4] * 2 + memo[i - 6] * 2 + 2;
            // memo[8] = memo[6] * memo[2] + memo[4] * 2 + memo[2] * 2 + 2;
            // memo[6] = memo[4] * memo[2] + memo[2] * 2 + 2
            for (int j = i - 4; j >= 2; j -= 2) {
                memo[i] += memo[j] * 2;
            }
        }
        print();
    }
    void print() {
        cout << memo[n] << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2133 boj2133;
    boj2133.solve();
    return 0;
}