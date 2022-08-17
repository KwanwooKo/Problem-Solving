#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ2293 {
private:
    int n, k;
    int memo[10001];
    vector<int> coin;
public:
    BOJ2293() {
        cin >> n >> k;
        for (int i = 0; i <= 10000; i++) {
            memo[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            coin.push_back(num);
        }
        memo[0] = 1;
        sort(coin.begin(), coin.end());
    }
    void solve() {
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= k; j++) {
                memo[j] += memo[j - coin[i]];
            }
        }
        // display();
        print();
    }
    void display() {
        for (int i = 0; i <= k; i++) {
            cout << memo[i] << ' ';
        }
        cout << endl;
    }
    void print() {
        cout << memo[k] << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2293 boj2293;
    boj2293.solve();
    return 0;
}