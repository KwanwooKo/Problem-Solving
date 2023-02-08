#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

class Solution {
    private:
        ll n;
        ll arr[100000];
        ll ans;
    public:
        Solution() {
            ans = -1;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        }
        void printList(ll left, ll right) {
            for (int i = left; i <= right; i++) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        int parametricSearch(ll left, ll right) {
            // 기저 조건 => 원소가 하나인 경우
            if (left == right) {
                return arr[left];
            }
            ll mid = (left + right) / 2;
            // 부분 문제 2개 처리
            ll ret = max(parametricSearch(left, mid), parametricSearch(mid + 1, right));
            ll curLeft = mid;
            ll curRight = mid + 1;
            ll height = min(arr[curLeft], arr[curRight]);
            
            ret = max(ret, height * 2);
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
            
            //printList(left, right);
            //cout << "ret: " << ret << endl;
            return ret;
        }

        void solve() {
            ans = parametricSearch(0, n);
            cout << ans << endl;
        }

};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
