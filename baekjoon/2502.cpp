#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ2502 {
private:
    int d, cmp;
    int ans[3];
    int memo_a[31];
    int memo_b[31];
public:
    BOJ2502() {
        cin >> d >> cmp;
        for (int i = 0; i <= 30; i++) {
            memo_a[i] = 0;
            memo_b[i] = 0;
        }
        ans[1] = 0, ans[2] = 0;
        memo_a[1] = 1;
        memo_b[2] = 1;
    }
    void solve() {
        for (int i = 3; i <= 30; i++) {
            memo_a[i] = memo_a[i - 1] + memo_a[i - 2];
            memo_b[i] = memo_b[i - 1] + memo_b[i - 2];
        }
        print();
//        display();
    }
    void display() {
        for (int i = 1; i <= d; i++) {
            cout << memo_a[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i <= d; i++) {
            cout << memo_b[i] << ' ';
        }
        cout << endl;

    }
    void print() {
        int k_a = memo_a[d];
        int k_b = memo_b[d];
        int max_value = cmp / k_a;
        bool flag = false;
        for (int i = 1; i <= max_value; i++) {
            if (flag) break;
            for (int j = 1; j <= max_value; j++) {
                if (k_a * i + k_b * j == cmp) {
                    ans[1] = i, ans[2] = j;
                    flag = true;
                    break;
                }
            }
        }
        cout << ans[1] << endl << ans[2] << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2502 boj2502;
    boj2502.solve();
    return 0;
}