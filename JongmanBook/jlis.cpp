#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
typedef long long ll;
using namespace std;

class Solution {
    private:
        int n, m;
        vector<ll> A;
        vector<ll> B;
        vector<ll> cacheA;
        vector<ll> cacheB;
        vector<ll> ans;
    public:
        // initialization
        Solution() {
            // to use vector.back()
            cacheA.push_back(0);
            cacheB.push_back(0);
            cin >> n >> m;
            // make A list
            for (int i = 0; i < n; i++) {
                ll num;
                cin >> num;
                A.push_back(num);
            }
            // make B list
            for (int i = 0; i < m; i++) {
                ll num;
                cin >> num;
                B.push_back(num);
            }
        }
        void parametricSearch(int start, int end, ll toFind, vector<ll>& list) {
            if (start >= end) {
                list[end] = toFind;
                return;
            }
            int mid = (start + end) / 2;
            if (toFind < list[mid]) {
                parametricSearch(start, mid, toFind, list);
            } else if (toFind == list[mid]) {
                return;
            } else {
                parametricSearch(mid + 1, end, toFind, list);
            }
        }
        /* make LIS by using greedy algorithm */
        // list == cache,  arr == A or B
        void makeLis(vector<ll>& list, vector<ll>& arr) {
            // compare list.back
            for (int i = 0; i < arr.size(); i++) {
                if (list.back() < arr[i]) {
                    list.push_back(arr[i]);
                } else {
                    parametricSearch(0, list.size() - 1, arr[i], list);
                }
            }
        }
        // merge cacheA and cacheB
        void mergeList() {
            int indexA = 1, indexB = 1;
            // merge list until a single index reached the end
            while (indexA < cacheA.size() && indexB < cacheB.size()) {
                if (cacheA[indexA] > cacheB[indexB]) {
                    // case 1: value of cacheA is larger than cacheB
                    ans.push_back(cacheB[indexB]);
                    indexB++;
                } else if (cacheA[indexA] == cacheB[indexB]) {
                    // case 2: equal value
                    ans.push_back(cacheA[indexA]);
                    indexA++;
                    indexB++;
                } else {
                    // case 3: value of cacheB is larger than cacheA
                    ans.push_back(cacheA[indexA]);
                    indexA++;
                }
            }
            // if the while loop finished because of indexA
            if (indexA == cacheA.size()) {
                // compare the ans and cacheB
                for (int i = indexB; i < cacheB.size(); i++) {
                    if (ans.back() < cacheB[i]) {
                        ans.push_back(cacheB[i]);
                    } else {
                        break;
                    }
                }
            }
            // otherwise
            if (indexB == cacheB.size()) {
                for (int i = indexA; i < cacheA.size(); i++) {
                    if (ans.back() < cacheA[i]) {
                        ans.push_back(cacheA[i]);
                    } else {
                        break;
                    }
                }
            }
        }

        // print cacheA or cacheB
        void printList(vector<ll>& list) {
            cout << endl << "==================== print list   ======================" << endl;
            for (int i = 0; i < list.size(); i++) {
                cout << list[i] << ' ';
            }
            cout << endl;
        }
        void solve() {
            makeLis(cacheA, A);
            makeLis(cacheB, B);
            mergeList();
            cout << ans.size() << endl;
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
