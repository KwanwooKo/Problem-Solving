#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

namespace Solve {
    class Solution {
    public:
        Solution(string _s) : s(_s) {}

        string reverse(string::iterator& it) {
            char head = *(it++);
            if (head == 'w' || head == 'b') {
                return string(1, head);
            }
            string upperLeft = reverse(it);
            string upperRight = reverse(it);
            string lowerLeft = reverse(it);
            string lowerRight = reverse(it);

            return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
        }

        void solve() {
            string::iterator it = s.begin();
            cout << reverse(it) << '\n';

        }

    private:
        string s;
    };
}


namespace Basic {
    const int BOARDSIZE = 17;
    char board[BOARDSIZE][BOARDSIZE];

    void printBoard() {
        for (int i = 1; i < BOARDSIZE; i++) {
            for (int j = 1; j < BOARDSIZE; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }


    class Solution {
    public:
        Solution(string _s) : s(_s) {}

        // 근데 이러면 len은 대체 어디서 가져오는데?
        void decompress(string::iterator& it, int x, int y, int len) {
            char head = *(it++);

            if (head == 'b' || head == 'w') {
                for (int i = 0; i < len; i++) {
                    for (int j = 0; j < len; j++) {
                        board[x + i][y + j] = head;
                    }
                }
            }
            else {
                int half = len / 2;
                decompress(it, x + half, y, half);
                decompress(it, x + half, y + half, half);
                decompress(it, x, y, half);
                decompress(it, x, y + half, half);
            }
        }


        void printString(string::iterator& it) {
            int i = 0;
            while (it + i != s.end()) {
                cout << *(it + i);
                i++;
            }
            cout << '\n';
        }

        int getInitLength(string::iterator& it, int depth) {
            // cout << "depth: " << depth << '\n';
            // printString(it);
            int ret = 0;
            char head = *(it);
            if (head == 'x') {
                it++;
                ret = max(ret, getInitLength(it, depth + 1));
            }

            for (int i = 0; i < 4; i++) {
                char tmp = *(it++);
                if (tmp == 'x') {
                    ret = max(ret, getInitLength(it, depth + 1));
                }
            }

            return max(ret, depth);
        }

        int pow(int n) {
            int ret = 1;
            for (int i = 0; i < n; i++) {
                ret *= 2;
            }
            return ret;
        }

        void solve() {
            string::iterator it = s.begin();
            int len = 0;
            if (*it != 'x') {
                len = 1;
            }
            else {
                len = pow(getInitLength(it, 0));
            }

            it = s.begin();
            decompress(it, 1, 1, len);
        }

    private:
        string s;
    };
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        string s = "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb";
        // string s = "xbwwb";
        cin >> s;

        Solve::Solution sol(s);
        sol.solve();

    }
}