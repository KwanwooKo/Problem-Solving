#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector<int> ans;
    while (t--) {
        bool check[1001] = {false, };
        vector<int> d[1001];
        int n, m;
        cin >> n >> m;
        int count = 0;
        for (int i = 0 ; i < m; i++) {
            int from, to;
            cin >> from >> to;
            d[from].push_back(to);
            d[to].push_back(from);
        }

        for (int i = 1; i <= n; i++) {
            if (check[i]) continue;
            check[i] = true;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();

                for (int c: d[x]) {
                    if (check[c]) continue;
                    check[c] = true;
                    q.push(c);
                    count++;
                }
            }
        }

        cout << count << endl;
    }


    return 0;
}

