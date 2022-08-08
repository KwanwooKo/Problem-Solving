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
int disjoint_sets[100];
vector<pair<double, double>> stars;
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        stars.push_back({x, y});
    }
    for (int i = 0; i < 100; i++) {
        disjoint_sets[i] = i;
    }
    // 별 순서에 따라 index 배정
    // (4, 1) (5, 8) (2, 1) (8, 4) (2, 9) (1, 4)
    vector<tuple<double, int, int>> edges;
    for (int i = 0; i < stars.size() - 1; i++) {
        for (int j = i + 1; j < stars.size(); j++) {
            double x1 = stars[i].first;
            double y1 = stars[i].second;
            double x2 = stars[j].first;
            double y2 = stars[j].second;
            double dist = sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
            edges.push_back({dist, i, j});
        }
    }
    // 간선 정렬
    sort(edges.begin(), edges.end());
    double ans = 0.0;
    for (int i = 0; i < edges.size(); i++) {
        double dist = get<0>(edges[i]);
        int index1 = get<1>(edges[i]);
        int index2 = get<2>(edges[i]);
        if (find_parents(index1) != find_parents(index2)) {
            ans += dist;
            make_sets(index1, index2);
        }
    }
    printf("%0.2lf", ans);
    return 0;
}