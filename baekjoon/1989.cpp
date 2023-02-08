#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

class Solution {
    private:
        int n;
        ll arr[100001];
        int startIdx, endIdx;
        ll maxSum;
    public:
        Solution() {
            cin >> n;
            memset(arr, 0, sizeof(arr));
            for (int i = 1; i <= n; i++) {
                cin >> arr[i];
            }
            startIdx = 1, endIdx = 1, maxSum = -1;
        }
        ll go(int start, int end) {
            if (start == end) {
                return arr[end] * arr[end];
            }
            int mid = (start + end) / 2;
            // left , right ret
            ll retLeft = go(start, mid);
            ll retRight = go(mid + 1, end);
            ll ret = max(retLeft, retRight);
            if (retLeft > maxSum) {
                startIdx = start;
                endIdx = mid;
                maxSum = retLeft;
            }

            if (retRight > maxSum) {
                startIdx = mid + 1;
                endIdx = end;
                maxSum = retRight;
            }

            int left = mid;
            int right = mid + 1;
            ll sum = arr[left] + arr[right];
            ll height = min(arr[left], arr[right]);
            if (sum * height > maxSum) {
                maxSum = sum * height;
                startIdx = left;
                endIdx = right;
            }
            ret = max(ret, sum * height);

            while (start < left || right < end) {
                if (right < end && (start == left || arr[left - 1] < arr[right + 1])) {
                    height = min(height, arr[++right]);
                    sum += arr[right];
                } else {
                    height = min(height, arr[--left]);
                    sum += arr[left];
                }
                if (maxSum < sum * height) {
                    startIdx = left, endIdx = right;
                    maxSum = sum * height;
                }
                ret = max(ret, sum * height);
            }
            return ret;
        }
        void solve() {
            ll ans = go(1, n);
            cout << ans << endl;
            cout << startIdx << ' ' << endIdx << endl;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}


