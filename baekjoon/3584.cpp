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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int node[10001] = {0, };
        int parent, child, node_num;
        cin >> node_num;
        for (int i = 0; i < node_num - 1; i++) {
            cin >> parent >> child;
            node[child] = parent;
        }
        int first, second;
        vector<int> first_list;
        vector<int> second_list;
        cin >> first >> second;
        while (1) {
            if (node[first] == 0) {
                first_list.push_back(first);
                break;
            }
            first_list.push_back(first);
            first = node[first];
        }
        while (1) {
            if (node[second] == 0) {
                second_list.push_back(second);
                break;
            }
            second_list.push_back(second);
            second = node[second];
        }
        // 출력
//        for (int i = 0; i < first_list.size(); i++) {
//            cout << first_list[i] << ' ';
//        }
//        cout << endl;
//        for (int i = 0; i < second_list.size(); i++) {
//            cout << second_list[i] << ' ';
//        }
//        cout << endl;
        //
        bool flag = false;
        int ans = -1;
        for (int i = 0; i < first_list.size(); i++) {
            for (int j = 0; j < second_list.size(); j++) {
                if (first_list[i] == second_list[j]) {
                    ans = first_list[i];
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        cout << ans << endl;
    }
    return 0;
}