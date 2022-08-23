#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ1939 {
private:
    int n, m, start, end, ans;
    vector<tuple<int, int, int>> edges;
    int disjoint_sets[100001];
    int node_price[100001];
    bool check[100001];
    vector<pair<int, int>> ansList[100001];
public:
    BOJ1939() {
        ans = -1;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int from, to, price;
            cin >> from >> to >> price;
            edges.push_back({price, from, to});
        }
        sort(edges.begin(), edges.end(), greater());
        cin >> start >> end;
        for (int i = 0; i <= n; i++) {
            disjoint_sets[i] = i;
            node_price[i] = 0;
            check[i] = false;
        }
        node_price[start] = INF;
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
        } else {
            disjoint_sets[a] = b;
        }
    }
    void display() {
//        for (int i = 1; i <= n; i++) {
//            for (int j = 0; j < ansList[i].size(); j++) {
//                cout << i << ' ' << ansList[i][j].first << ' ' << ansList[i][j].second << endl;
//            }
//        }
        for (int i = 1; i <= n; i++) {
            cout << node_price[i] << ' ';
        }
        cout << endl;
    }
    void print() {
        queue<int> q;
        q.push(start);
//        for (int i = 0; i < ansList[start].size(); i++) {
//            int next = ansList[start][i].first;
//            int price = ansList[start][i].second;
//            node_price[next] = price;
//        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < ansList[curr].size(); i++) {
                int next = ansList[curr][i].first;
                int price = ansList[curr][i].second;
                int takingPrice = min(node_price[curr], price);
                if (takingPrice > node_price[next]) {
                    node_price[next] = takingPrice;
                    q.push(next);
                }
            }
        }
        cout << node_price[end] << endl;
    }
    void solve() {
        for (int i = 0; i < edges.size(); i++) {
            int price = get<0>(edges[i]);
            int from = get<1>(edges[i]);
            int to = get<2>(edges[i]);
            if (find_parents(from) != find_parents(to)) {
                make_sets(from, to);
                ansList[from].push_back({to, price});
                ansList[to].push_back({from, price});
            }
        }
        print();
//        display();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ1939 boj;
    boj.solve();
    return 0;
}