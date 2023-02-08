#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n;
        vector<int> inorder;
        vector<int> postorder;
    public:
        Solution() {
            cin >> n;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                inorder.push_back(num);
            }
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                postorder.push_back(num);
            }
        }
        int findRoot(int inorderStart, int inorderEnd, int root) {
            int L = -1;
            for (int i = inorderStart; i < inorderEnd; i++) {
                if (inorder[i] == root) return i;
            }
            return L;
        }
        void printPreOrder(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd) {
            if (inorderStart < inorderEnd) {
                const int root = postorder[postorderEnd - 1];
                const int L = findRoot(inorderStart, inorderEnd, root);
                cout << root << ' ';
                printPreOrder(inorderStart, L, postorderStart, postorderStart + L - inorderStart);
                printPreOrder(L + 1, inorderEnd, postorderStart + L - inorderStart, postorderEnd - 1);
            }
        }
        void solve() {
            printPreOrder(0, inorder.size(), 0, postorder.size());
            cout << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
    return 0;
}
