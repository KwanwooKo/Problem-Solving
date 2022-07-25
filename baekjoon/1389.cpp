#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int> edges[101];
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    int ans_sum = 2147483647;
    int ans_index = 0;
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        int map[101] = {0, };
        bool check[101] = {0, };
        q.push(i);
        check[i] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : edges[node]) {
                if (check[next]) continue;
                check[next] = true;
                map[next] = map[node] + 1;
                q.push(next);
            }
        }
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += map[j];
        }
        if (ans_sum > sum) {
            ans_sum = sum;
            ans_index = i;

        }
    }
    cout << ans_index << endl;
    return 0;
}