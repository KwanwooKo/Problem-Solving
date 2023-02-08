#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
    private:
        int n;
        int map[65][65];
    public:
        Solution() {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    scanf("%1d", &map[i][j]);
                }
            }
        }
        // 해당 구역이 압축이 가능한지 확인
        bool checkCompress(int row, int col, int size) {
            bool ret = true;
            int cmp = map[row][col];
            for (int i = row; i < row + size; i++) {
                for (int j = col; j < col + size; j++) {
                    if (cmp != map[i][j]) {
                        ret = false;
                        break;
                    }
                }
                if (ret == false) break;
            }
            return ret;
        }
        void go(int row, int col, int size) {
            // 기저조건: 한칸 인 경우
            if (size == 1) {
                cout << map[row][col];
                return;
            }
            // 기저조건: 해당 영역이 압축 가능하다면
            if (checkCompress(row, col, size)) {
                cout << map[row][col];
                return;
            }
            // 4개 영역으로 분할
            cout << "(";
            go(row, col, size / 2);
            go(row, col + size / 2, size / 2);
            go(row + size / 2, col, size / 2);
            go(row + size / 2, col + size / 2, size / 2);
            cout << ")";
        }
        void printMap() {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cout << map[i][j] << ' ';
                }
                cout << endl;
            }
        }
        void solve() {
            go(1, 1, n);
            cout << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
