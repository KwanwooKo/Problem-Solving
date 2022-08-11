#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ4195 {
private:
    // 행성을 index 로 봐야돼
    // 인접한 두 점이 무조건 최단경로 중 하나
    int disjoint_sets[100000];
    int set_size[100000];
    map<string, int> name;
    int person_num;
public:
    BOJ4195(int n) {
        this->person_num = n;
        for (int i = 0; i < 100000; i++) {
            disjoint_sets[i] = i;
            set_size[i] = 1;
        }
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
        int name_size = 0;
        for (int i = 0; i < person_num; i++) {
            string a, b;
            cin >> a >> b;
            if (name.count(a) == 0) {
                name[a] = name_size;
                name_size++;
            }
            if (name.count(b) == 0) {
                name[b] = name_size;
                name_size++;
            }
            int root_a = find_parents(name[a]);
            int root_b = find_parents(name[b]);
            if (root_a != root_b) {
                make_sets(name[a], name[b]);
                int set_a = set_size[root_a];
                int set_b = set_size[root_b];
                set_size[root_a] += set_b;
                set_size[root_b] += set_a;
                cout << set_size[root_a] << endl;
            }
            else {
                // cout << max(set_size[find_parents(name[b])], set_size[find_parents(name[a])]) << endl;
                cout << set_size[root_a] << endl;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        BOJ4195 boj4195(n);
        boj4195.solve();
    }
    return 0;
}