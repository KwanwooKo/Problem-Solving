#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

class Solution {
    private:
        ll ans;
        ll n;
        vector<ll> arr;
    public:
        Solution(int t) {
            ans = 0;
            n = t;
            for (int i = 0; i < t; i++) {
                ll num;
                cin >> num;
                arr.push_back(num);
            }
        }
        void printList(int left, int right) {
            for (int i = left; i <= right; i++) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        ll parametricSearch(int left, int right) {
            // 기저조건: 원소가 하나만 남은 경우
            if (left == right) {
                return arr[left];
            }
            int mid = (left + right) / 2;
            // 왼쪽, 오른쪽에서의 최댓값 찾기
            ll ret = max(parametricSearch(left, mid), parametricSearch(mid + 1, right));

            int lo = mid;
            int hi = mid + 1;
            ll height = min(arr[lo], arr[hi]);
            
            ret = max(ret, height * 2);
            // 이제 가운데서 뻗어나가는 거 처리
            while (left < lo || hi < right) {
                if (hi < right && (lo == left || arr[lo - 1] < arr[hi + 1])) {
                    hi++;
                    height = min(height, arr[hi]);
                } else {
                    lo--;
                    height = min(height, arr[lo]);
                }
                ret = max(ret, height * (hi - lo + 1));
            }
            return ret;
        }

        void solve() {
            ans = parametricSearch(0, n - 1);
            cout << ans << endl;
        }

};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    while (1) {
        cin >> t;
        if (t == 0) {
            break;
        }
        Solution* sol = new Solution(t);
        sol->solve();
        delete sol;
    }
}
