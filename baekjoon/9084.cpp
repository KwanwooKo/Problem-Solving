#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ9084 {
private:
    int coin_number;
    vector<int> coin;   // 알아서 정렬됨
    int memo[10001]; // {가짓수 , 마지막에 사용된 코인}
    int goal;
public:
    BOJ9084() {
        cin >> coin_number;
        for (int i = 0; i < coin_number; i++) {
            int num;
            cin >> num;
            coin.push_back(num);
        }
        for (int i = 0; i <= 10000; i++) {
            memo[i] = 0;
        }
        memo[0] = 1;
        cin >> goal;

    }
    void solve() {
        for (int i = 0; i < coin_number; i++) {
            for (int j = coin[i]; j <= goal; j++) {
                memo[j] = memo[j] + memo[j - coin[i]];
            }
        }
//        display();
        print();
    }
    void display() {
        for (int i = 1; i <= goal; i++) {
            cout << memo[i] << ' ';
        }
        cout << endl;
    }
    void print() {
        cout << memo[goal] << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        BOJ9084 boj;
        boj.solve();
    }

    return 0;
}