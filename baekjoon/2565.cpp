#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ2565 {
private:
    int n;
    int lis;
    int elec_line[501];
    int memo[501];
    vector<pair<int, int> > sorted_point;
public:
    BOJ2565() {
        cin >> n;
        lis = 0;
        for (int i = 0; i <= 500; i++) {
            elec_line[i] = 0;
            memo[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            int from, to;
            cin >> from >> to;
            elec_line[from] = to;
        }
        for (int i = 1; i <= 500; i++) {
            for (int j = 1; j < i; j++) {
                if (elec_line[i] == 0 || elec_line[j] == 0) continue;
                if (elec_line[j] < elec_line[i]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
        }
    }
    void solve() {
        // display();
        print();
    }
    void display() {
        for (int i = 1; i <= 10; i++) {
            cout << memo[i] << ' ';
        }
        cout << endl;
    }
    void print() {
        for (int i = 1; i <= 500; i++) {
            lis = max(lis, memo[i]);
        }
        cout << n - lis << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2565 boj2565;
    boj2565.solve();
    return 0;
}