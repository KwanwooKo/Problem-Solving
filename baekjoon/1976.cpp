#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
int disjoint_sets[201];
int find_parents(int node) {
    if (node != disjoint_sets[node]) {
        disjoint_sets[node] = find_parents(disjoint_sets[node]);
    }
    return disjoint_sets[node];
}
void make_sets(int a, int b) {
    a = find_parents(a);
    b = find_parents(b);
    if (a < b) {
        disjoint_sets[b] = a;
    }
    else {
        disjoint_sets[a] = b;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 200; i++) {
        disjoint_sets[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int connected;
            cin >> connected;
            if (find_parents(i) != find_parents(j) && connected) {
                make_sets(i, j);
            }
        }
    }
    vector<int> list;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        list.push_back(num);
    }
    bool ans_flag = true;
    for (int i = 0; i < list.size(); i++) {
        for (int j = i + 1; j < list.size(); j++) {
            int curr = list[i];
            int next = list[j];
            if (find_parents(curr) != find_parents(next)) {
                ans_flag = false;
            }
        }
    }
    if (ans_flag) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}