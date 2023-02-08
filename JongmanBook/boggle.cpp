#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
class Solution {
private:
    int size;
    char arr[6][6];
    string words;
public:
    Solution() {
        // set size 5
        this->size = 5;
        cin >> words;
        // set arr as the boggle map
        cout << "boggle map" << endl;
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                cin >> arr[i][j];
            }
        }
    }

    bool hasWord(int i, int j, int index) {
        if (index == words.size() - 1) {
            if (words[index] == arr[i][j]) return true;
            else return false;
        }
        for (int k = 0; k < 8; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 1 || ny < 1 || nx > size || ny > size) continue;
            if (arr[i][j] == words[index]) {
               bool find = hasWord(nx, ny, index + 1);
               if (find == true) return true;
            }
        }
        return false;
    }
    void solve() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                bool find = hasWord(i, j, 0);
                if (find == true) {
                    cout << "찾았다!" << endl;
                    return;
                }
            }
        }
    }
};

int main(void) {
    cout << "검색할 문자열을 입력하세요: ";
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
