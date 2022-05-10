#include <iostream>
#include <cstdio>
#define endl '\n'
using namespace std;
long long dist[91][2];
int main(void) {
    int n;
    cin >> n;
    dist[1][1] = 1;
    dist[1][0] = 0;
    for (int i = 2; i <= 90; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                dist[i][j] = dist[i-1][1] + dist[i-1][0];
            }
            if (j == 1) {
                dist[i][j] = dist[i-1][0];
            }
        }
    }
    long long ans = dist[n][0] + dist[n][1];
    cout << ans << endl;
    return 0;
}
