#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

// 7
// 7 1 5 9 6 7 3
class Solution {
    private:
        int n;
        int arr[20000];
        int ans;
    public:
        Solution() {
            ans = -1;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        }
        void printList(int left, int right) {
            for (int i = left; i <= right; i++) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        int parametricSearch(int left, int right) {
            // 기저 조건 => 원소가 하나인 경우
            if (left == right) {
                return arr[left];
            }
            int mid = (left + right) / 2;
            int ret = max(parametricSearch(left, mid), parametricSearch(mid + 1, right));

            int curLeft = mid;
            int curRight = mid + 1;
            int height = min(arr[curLeft], arr[curRight]);

            while (left < curLeft || curRight < right) {
                if (curRight < right && (curLeft == left || arr[curLeft - 1] < arr[curRight + 1])) {
                    curRight++;
                    height = min(height, arr[curRight]);
                } else {
                    curLeft--;
                    height = min(height, arr[curLeft]);
                }
                ret = max(ret, height * (curRight - curLeft + 1));
            }
            return ret;
        }

        void solve() {
            ans = parametricSearch(0, n - 1);
            cout << ans << endl;
        }

};

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        Solution* sol = new Solution();
        sol->solve();
        delete sol;
    }
}
