#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n;
        vector<int> preorder;
        vector<int> inorder;
    public:
        Solution() {
            cin >> n;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                preorder.push_back(num);
            }
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                inorder.push_back(num);
            }
        }
        vector<int> slice(const vector<int>& v, int a, int b) {
            return vector<int>(v.begin() + a, v.begin() + b);
        }
        void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
            const int N = preorder.size();
            if (preorder.empty()) return;
            const int root = preorder[0];
            const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
            //const int R = N - L - 1;
            printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
            printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
            cout << root << ' ';
        }
        void solve() {
            printPostOrder(preorder, inorder);
            cout << endl;
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
    return 0;
}
