#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ2512 {
private:
    int n, ans, maxNum, upperBound;
    vector<int> arr;
public:
    BOJ2512() {
        cin >> n;
        ans = -1;
        upperBound = -1;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr.push_back(num);
            upperBound = max(num, upperBound);
        }
        cin >> maxNum;
    }
    void parametricSearch(int start, int end) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        int sum = check(0, mid);
        if (sum == maxNum) {
            ans = mid;
            return;
        }
        else if (sum < maxNum) {
            ans = mid;
            parametricSearch(mid + 1, end);
        }
        else {
            parametricSearch(start, mid - 1);
        }
    }
    int check(int sum, int upper_bound) {
        for (int i = 0; i < n; i++) {
            if (arr[i] <= upper_bound) {
                sum += arr[i];
            }
            else {
                sum += upper_bound;
            }
        }
        return sum;
    }
    void print() {
        cout << ans << endl;
    }
    void solve() {
        parametricSearch(1, upperBound);
        print();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2512 boj;
    boj.solve();

    return 0;
}