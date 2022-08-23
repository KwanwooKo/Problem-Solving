#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ12015 {
private:
    vector<int> arr;
    vector<int> ans;
    int n;
public:
    BOJ12015() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        ans.push_back(0);
    }
    void parametricSearch(int start, int end, int toFind) {
        if (start >= end) {
            ans[end] = toFind;
            return;
        }
        int mid = (start + end) / 2;
        if (ans[mid] < toFind) {
            parametricSearch(mid + 1, end, toFind);
        } else {
            parametricSearch(start, mid, toFind);
        }

    }
    void print() {
//        for (int i = 0; i < ans.size(); i++) {
//            cout << ans[i] << ' ';
//        }
//        cout << endl;
        cout << ans.size() - 1 << endl;
    }
    void solve() {
        for (int i = 0; i < n; i++) {
            if (ans.back() < arr[i]) {
                ans.push_back(arr[i]);
            } else {
                parametricSearch(0, ans.size() - 1, arr[i]);
            }
        }
        print();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ12015 boj;
    boj.solve();

    return 0;
}