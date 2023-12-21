#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 
 * 이거 중복해서 세는 경우를 잘 제거해야 돼
 * 중복해서 세는 경우를 방지하려면 왼쪽 위에서부터 오른쪽 아래로 채워넣어야 되는데
 * 이거를 상대 좌표 말고 절대 좌표로 설정해서 하면
 * rotate 활용해서 풀기 가능
 * 근데 이 때 절대 좌표로 지정할 때 어느 좌표를 기준으로 paste 되는지 확인 해야돼
 */

class Solution {
private:
    const int width, height;
    int board[20][20] = {{0}};
public:
    void printBoard();
    void printBlock(int (*)[2]);

    Solution(int w, int h): width(w), height(h) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                char c;
                cin >> c;
                if (c == '#') board[i][j] = 1;
            }
        }
    }

    void rotate(int (*block)[2]) {
        int tmp[2][2] = {0};
        
        copy(&block[0][0], &block[0][0] + 4, &tmp[0][0]);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                block[i][j] = tmp[j][1 - i];
            }
        }
    }

    bool cannotPaste(int x, int y, const int (*block)[2]) {
        for (int i = x; i < x + 2; i++) {
            for (int j = y; j < y + 2; j++) {
                if (i < 0 || j < 0 || i >= height || j >= width) return true;
                if (block[i - x][j - y] == 2 && board[i][j] != 0) {
                    return true;
                }
            }
        }
        return false;
    }

    void paste(int x, int y, int (*block)[2]) {
        for (int i = x; i < x + 2; i++) {
            for (int j = y; j < y + 2; j++) {
                if (block[i - x][j - y] == 2) {
                    board[i][j] = 2;
                }
            }
        }
    }

    void unpaste(int x, int y, int (*block)[2]) {
        for (int i = x; i < x + 2; i++) {
            for (int j = y; j < y + 2; j++) {
                if (block[i - x][j - y] == 2) {
                    board[i][j] = 0;
                }
            }
        }
    }

    int cover() {
        int x = -1, y = -1, ret = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == 0) {
                    x = i, y = j;
                    break;
                }
            }
            if (y != -1) break;
        }

        if (y == -1) return 1;

        // int block[2][2] = {{2, 0}, {2, 2}};
        int block[2][2] = {{2, 2}, {2, 0}};
        for (int k = 0; k < 4; k++) {
            if (k > 0) rotate(block);
            if (k == 2) {
                if (cannotPaste(x, y - 1, block)) continue;
            }
            else {
                if (cannotPaste(x, y, block)) continue;
            }
            if (k == 2) paste(x, y - 1, block);
            else paste(x, y, block);
            ret += cover();

            if (k == 2) unpaste(x, y - 1, block);
            else unpaste(x, y, block);
        }

        return ret;
    }

    void test() {
        int block[2][2] = {{2, 2}, {2, 0}};
        for (int i = 0; i < 4; i++) {
            printBlock(block);
            rotate(block);
        }

        // board[0][1] = 2;
        // board[0][2] = 2;
        // board[1][1] = 2;
        // rotate(block);
        // paste(0, 2, block);
        // printBoard();
        
    }

    void solve() {
        // test();
        cout << cover() << '\n';

    }

};
void Solution::printBlock(int (*block)[2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << block[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void Solution::printBoard() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 0) cout << ".";
            else if (board[i][j] == 1) cout << "#";
            else cout << "B";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> h >> w;
        Solution sol(w, h);
        sol.solve();
    }
}