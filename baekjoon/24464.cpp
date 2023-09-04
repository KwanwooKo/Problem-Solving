#include <iostream>
#define endl '\n'
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll cache[200001][5];
void init() {
    for (int i = 0; i < 5; i++) {
        cache[1][i] = 1;
    }
}
int main(void) {
    int n;
    cin >> n;
    init();
    for (int i = 2; i <= n; i++) {
        cache[i][0] = (cache[i - 1][1] % MOD + cache[i - 1][2] % MOD + cache[i - 1][3] % MOD + cache[i - 1][4] % MOD) % MOD;
        cache[i][1] = (cache[i - 1][0] % MOD + cache[i - 1][3] % MOD + cache[i - 1][4] % MOD) % MOD;
        cache[i][2] = (cache[i - 1][0] % MOD + cache[i - 1][4] % MOD) % MOD;
        cache[i][3] = (cache[i - 1][0] % MOD + cache[i - 1][1] % MOD) % MOD;
        cache[i][4] = (cache[i - 1][0] % MOD + cache[i - 1][1] % MOD + cache[i - 1][2] % MOD) % MOD;
    }
    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += (cache[n][i] % MOD);
        ans %= MOD;
    }
    
    cout << ans << endl;
    return 0;
}

