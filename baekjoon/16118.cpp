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
int fox_edges[4001][4001];
int wolf_edges[4001][4001][2];
int wolf_price[4001][2];
int fox_price[4001];
bool check[4001][4001][2];
int n, d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        fox_price[i] = INF;
        wolf_price[i][0] = INF;
        wolf_price[i][1] = INF;
    }
    fox_price[1] = 0;
    wolf_price[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                fox_edges[i][j] = 0;
                wolf_edges[i][j][0] = 0;
                wolf_edges[i][j][1] = 0;
                check[i][j][0] = true;
                check[j][i][1] = true;
            }
            else {
                fox_edges[i][j] = INF;
                wolf_edges[i][j][0] = INF;
                wolf_edges[i][j][1] = INF;
            }
        }
    }
    for (int i = 0; i < d; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        fox_edges[from][to] = price * 2;
        fox_edges[to][from] = price * 2;
        wolf_edges[from][to][1] = price;
        wolf_edges[from][to][0] = price * 4;
        wolf_edges[to][from][1] = price;
        wolf_edges[to][from][0] = price * 4;

    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> fox_pq;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> wolf_pq;
    fox_pq.push({0, 1});
    wolf_pq.push({0, 1, 1});
    while (!fox_pq.empty()) {
        int price = fox_pq.top().first;
        int node = fox_pq.top().second;
        fox_pq.pop();
        if (fox_price[node] < price) continue;
        for (int i = 1; i <= n; i++) {
            if (i == node) continue;
            if (fox_edges[node][i] == INF) continue;
            if (price + fox_edges[node][i] < fox_price[i]) {
                fox_price[i] = price + fox_edges[node][i];
                fox_pq.push({fox_price[i], i});
            }
        }
    }

    while (!wolf_pq.empty()) {
        int price = get<0>(wolf_pq.top());
        int node = get<1>(wolf_pq.top());
        int count = get<2>(wolf_pq.top()) % 2;
        wolf_pq.pop();
        if (price > wolf_price[node][(count + 1) % 2]) continue;

        for (int i = 1; i <= n; i++) {
            if (i == node) continue;
            if (wolf_edges[node][i][count] == INF) continue;
            if (check[node][i][count]) continue;
            check[node][i][count] = true;
            if (wolf_edges[node][i][count] + price < wolf_price[i][count]) {
                wolf_price[i][count] = price + wolf_edges[node][i][count];
                wolf_pq.push({price + wolf_edges[node][i][count], i, count + 1});
            }
        }
    }

//    cout << "여우" << endl;
//    for (int i = 1; i <= n; i++) {
//        cout << fox_price[i] << ' ';
//    }
//    cout << endl;
//
//    cout << "늑대" << endl;
//    for (int i = 1; i <= n; i++) {
//        cout << i << ": " << wolf_price[i][0] << ' ' << wolf_price[i][1] << endl;
//    }
//    cout << endl;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        int wolf_min = min(wolf_price[i][0], wolf_price[i][1]);
        if (wolf_min > fox_price[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
