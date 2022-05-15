#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> list;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.push_back(num);
    }
    int index = n;
    swap(list[0], list[index - 1]);
    swap(list[0], list[index / 2]);

    sort(list.begin(), list.end());
    cout << list[m - 1] << endl;
    return 0;
}
