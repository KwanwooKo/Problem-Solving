#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
int height[501];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> height[i];
    }
    int curr = height[1];
    vector<int> list;
    int ans = 0;
    for (int i = 2; i <= m; i++) {
        if (curr >= height[i]) {
            list.push_back(height[i]);
        }
        else {
            if (i == m) {
                curr = height[m];
                for (int j = 0; j < list.size(); j++) {
                    ans += (curr - list[j]);
                }
            }
            else {
                // 중간에 curr 가 갱신된 경우
                for (int j = 0; j < list.size(); j++) {
                    ans += (curr - list[j]);
                }
                curr = height[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}