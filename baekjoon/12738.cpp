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
    public:
        Solution() {
            cin >> n;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                arr.push_back(num);
            }
            cache.push_back(arr[0]);
        }
        void parametricSearch(int start, int end, int toFind) {
            if (start >= end) {
                cache[end] = toFind;
                return;
            }
            int mid = (start + end) / 2;
            if (toFind < cache[mid]) {
                // case 1: if toFind is smaller than the cache[mid]
                parametricSearch(start, mid, toFind);
            } else if (toFind > cache[mid]) {
                // case 2: if toFind is larger than the cache[mid]
                parametricSearch(mid + 1, end, toFind);
            } else {
                return;
            }
        }
        void printAnswer() {
            cout << cache.size() << endl;
        }
        void makeLis() {
            for (int i = 1; i < n; i++) {
                if (cache.back() < arr[i]) {
                    cache.push_back(arr[i]);
                } else {
                    parametricSearch(0, cache.size() - 1, arr[i]);
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
