#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int cache[1001];
int main(void) {
    int n, ans = 0;
    cin >> n;
    vector<int> d(n + 1);
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    
    sort(d.begin(), d.end());
    
    for (int i = 1; i <= n; i++) {
        cache[i] = cache[i - 1] + d[i];
    }
    ans = cache[n] + 1;
    
    for (int i = 1; i <= n; i++) {
        if (d[i] <= cache[i - 1] + 1)
            continue;
        else {
            ans = cache[i - 1] + 1;
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}
