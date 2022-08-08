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
int disjoint_sets[1000001];
int find_parents(int x) {
    if (disjoint_sets[x] != x) {
        disjoint_sets[x] = find_parents(disjoint_sets[x]);
    }
    return disjoint_sets[x];
}
void make_sets(int from, int to) {
    from = find_parents(from);
    to = find_parents(to);
    if (from < to) {
        disjoint_sets[to] = from;
    }
    else {
        disjoint_sets[from] = to;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 1000000; i++) {
        disjoint_sets[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int flag, from, to;
        cin >> flag >> from >> to;
        if (from > to) 
            swap(from, to);
        // 팀 합치기
        if (flag == 0) {
            make_sets(from, to);
        }
        // 같은 팀 여부 확인
        if (flag == 1) {
            if (find_parents(from) == find_parents(to)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}