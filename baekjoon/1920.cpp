#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
vector<long long> d;
bool found;
void go(long long left, long long right, long long num) {
    long long mid = (left + right) / 2;
    if (left > right) {
        found = false;
        return;
    }
    if (d[left] == num || d[right] == num || d[mid] == num) {
        found = true;
        return;
    }
    if (num > d[mid]) {
        if (found) {
            return;
        }
        go(mid + 1, right - 1, num);
    }
    else if (num < d[mid]) {
        if (found) {
            return;
        }
        go(left + 1, mid - 1, num);
    }

}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        d.push_back(num);
    }
    sort(d.begin(), d.end());
    int t;
    cin >> t;
    while (t--) {
        found = false;
        long long num;
        cin >> num;
        go(0, d.size() - 1, num);
        if (found) {
            cout << "1" << endl;
        }
        else {
            cout << "0" << endl;
        }
    }
    return 0;
}


