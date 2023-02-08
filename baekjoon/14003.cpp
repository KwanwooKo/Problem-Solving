#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n;
        vector<int> arr;
        vector<int> cache;
        vector<int> ans;
        int index[1000000];
    public:
        Solution() {
            cin >> n;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                arr.push_back(num);
            }
            memset(index, -1, sizeof(index));
            cache.push_back(arr[0]);
            index[0] = 0;
        }
        void parametricSearch(int start, int end, int toFind, int cacheIndex) {
            if (start >= end) {
                cache[end] = toFind;
                index[cacheIndex] = end;
                return;
            }
            int mid = (start + end) / 2;
            if (toFind < cache[mid]) {
                // case 1: if toFind is smaller than the cache[mid]
                parametricSearch(start, mid, toFind, cacheIndex);
            } else if (toFind > cache[mid]) {
                // case 2: if toFind is larger than the cache[mid]
                parametricSearch(mid + 1, end, toFind, cacheIndex);
            } else {
                index[cacheIndex] = mid;
                return;
            }
        }
        int findMaxIndex() {
            int ret = -1;
            for (int i = 0; i < n; i++) {
                ret = max(ret, index[i]);
            }
            return ret;
        }
        void printAnswer() {
            int findIndex = findMaxIndex();
            for (int i = n - 1; i >= 0; i--) {
                if (index[i] == findIndex) {
                    findIndex--;
                    ans.push_back(arr[i]);
                }
            }
            cout << ans.size() << endl;
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        void printIndexArr() {
            cout << "index Arr" << endl;
            for (int i = 0; i < arr.size(); i++) {
                cout << index[i] << ' ';
            }
            cout << endl;
        }
        void makeLis() {
            int count = 1;
            for (int i = 1; i < n; i++) {
                if (cache.back() < arr[i]) {
                    cache.push_back(arr[i]);
                    index[i] = count++;
                } else {
                    parametricSearch(0, cache.size() - 1, arr[i], i);
                }
            }
        }
        void solve() {
            makeLis();
            //printIndexArr();
            printAnswer();
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
    return 0;
}
