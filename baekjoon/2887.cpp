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
class BOJ2887 {
private:
    // 행성을 index 로 봐야돼
    // 인접한 두 점이 무조건 최단경로 중 하나
    vector<tuple<int, int, int>> planet;
    vector<pair<int, int>> planet_x;
    vector<pair<int, int>> planet_y;
    vector<pair<int, int>> planet_z;
    vector<tuple<int, int, int>> edges;
    int disjoint_sets[100000];
    int ans;
public:
    BOJ2887(int n) {
        ans = 0;
        for (int i = 0; i < 100000; i++) {
            disjoint_sets[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            planet_x.push_back({x, i});
            planet_y.push_back({y, i});
            planet_z.push_back({z, i});
        }
        sort(planet_x.begin(), planet_x.end());
        sort(planet_y.begin(), planet_y.end());
        sort(planet_z.begin(), planet_z.end());
        for (int i = 0; i < n - 1; i++) {
            int curr = i;
            int next = i + 1;
            edges.push_back({abs(planet_x[curr].first - planet_x[next].first), planet_x[curr].second, planet_x[next].second});
            edges.push_back({abs(planet_y[curr].first - planet_y[next].first), planet_y[curr].second, planet_y[next].second});
            edges.push_back({abs(planet_z[curr].first - planet_z[next].first), planet_z[curr].second, planet_z[next].second});
        }
        sort(edges.begin(), edges.end());
    }
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
    void solve() {
        for (int i = 0; i < edges.size(); i++) {
            int price = get<0>(edges[i]);
            int curr = get<1>(edges[i]);
            int next = get<2>(edges[i]);
            if (find_parents(curr) != find_parents(next)) {
                make_sets(curr, next);
                ans += price;
            }
        }
        cout << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    BOJ2887* boj2887 = new BOJ2887(n);
    boj2887->solve();
    delete boj2887;
    return 0;
}