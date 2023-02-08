#include <iostream>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

class Solution {
    private:
        int n;
        ll arr[100000];
    public:
        Solution() {
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        }
        ll go(int start, int end) {
            if (start == end) {
                //cout << "[" << start << ", " << end << "]" << endl;
                //cout << "ret: " << arr[end] * arr[end] << endl;
                return arr[end] * arr[end];
            }
            int mid = (start + end) / 2;
            ll ret = max(go(start, mid), go(mid + 1, end));

            int left = mid - 1, right = mid + 1;
            ll height = arr[mid], sum = arr[mid];
            ret = max(ret, sum * height);

            while (start <= left || right <= end) {
                if (right <= end && (start > left || arr[left] < arr[right])) {
                    height = min(height, arr[right]);
                    sum += arr[right];
                    right++;
                } else {
                    height = min(height, arr[left]);
                    sum += arr[left];
                    left--;
                }
                ret = max(ret, sum * height);
            }
            //cout << "[" << start << ", " << end << "]" << endl;
            //cout << "ret: " << ret << endl;
            return ret;
        }
        void solve() {
            ll ans = go(0, n - 1);
            cout << ans << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
