#include <iostream>
#include <algorithm>
#define endl '\n'
#define WHITE 0
#define BLUE 1
#define NOTSAME 2
using namespace std;

class Solution {
    private:
        int n;
        int blue;
        int white;
        int map[129][129];
    public:
        Solution() {
            blue = 0;
            white = 0;
            cin >> n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> map[i][j];
                }
            }
        }
        bool checkSection(int row, int col, int size) {
            // 처음 색을 기준으로 그 색과 같은지 다른지 확인
            int color = map[row][col];
            for (int i = row; i < row + size; i++) {
                for (int j = col; j < col + size; j++) {
                    if (color != map[i][j]) return false;
                }
            }
            return true;
        }
        void go(int row, int col, int size) {
            // 기저조건: 색이 다 일치하는 경우
            if (checkSection(row, col, size)) {
                int color = map[row][col];
                if (color == WHITE) white++;
                if (color == BLUE) blue++;
                return;
            }
            // left up
            go(row, col, size / 2);
            // left down
            go(row + size / 2, col, size / 2);
            // right up
            go(row, col + size / 2, size / 2);
            // right down
            go(row + size / 2, col + size / 2, size / 2);
        }
        void solve() {
            go(0, 0, n);
            cout << white << endl << blue << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
