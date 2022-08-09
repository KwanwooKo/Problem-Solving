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
int disjoint_sets[100001];
bool check[100001];
int find_parents(int node) {
    if (disjoint_sets[node] != node) {
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
    int g, p;
    cin >> g >> p;
    int ans = 1;
    for (int i = 1; i <= g; i++) {
        disjoint_sets[i] = i;
    }
    vector<int> price;
    for (int i = 0; i < p; i++) {
        int num;
        cin >> num;
        price.push_back(num);
    }
    for (int i = 0; i < p; i++) {
        int num = price[i];
        int parent = find_parents(num);
        if (parent == 0) break;
        else {
            ans++;
            make_sets(parent, parent - 1);
        }
    }
    cout << ans - 1 << endl;
    return 0;
}