#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
class Solution {
    private:
        int r, c, posx, posy;
        char map[51][51];
        bool animalVisited[51][51];
        bool waterVisited[51][51];
        int animalCount[51][51];
        int waterCount[51][51];
        queue<pair<int, int>> animalQueue;
        queue<pair<int, int>> waterQueue;
    public:
        Solution() {
            cin >> r >> c;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    cin >> map[i][j];
                    if (map[i][j] == 'S') {
                        animalQueue.push(make_pair(i, j));
                        animalVisited[i][j] = true;
                    }
                    if (map[i][j] == '*') {
                        waterQueue.push(make_pair(i, j));
                        waterVisited[i][j] = true;
                    }
                    if (map[i][j] == 'D') {
                        posx = i;
                        posy = j;
                    }
                }
            }
        }
        void waterBfs() {
            int initwx = waterQueue.front().first;
            int initwy = waterQueue.front().second;
            int wcount = waterCount[initwx][initwy];
            while (!waterQueue.empty()) {
                int wx = waterQueue.front().first;
                int wy = waterQueue.front().second;
                if (waterCount[wx][wy] != wcount) break;
                waterQueue.pop();
                for (int k = 0; k < 4; k++) {
                    int nwx = wx + dx[k];
                    int nwy = wy + dy[k];
                    if (nwx < 1 || nwy < 1 || nwx > r || nwy > c) continue;
                    if (waterVisited[nwx][nwy]) continue;
                    if (map[nwx][nwy] == 'X') continue;
                    if (map[nwx][nwy] == 'D') continue;
                    map[nwx][nwy] = '*';
                    waterVisited[nwx][nwy] = true;
                    waterCount[nwx][nwy] = waterCount[wx][wy] + 1;
                    waterQueue.push(make_pair(nwx, nwy));
                }
            }
        }
        void bfs() {
            int prevAnimalCount = 0;
            while (!animalQueue.empty()) {
                int ax = animalQueue.front().first;
                int ay = animalQueue.front().second;
                if (prevAnimalCount != animalCount[ax][ay]) {
                    prevAnimalCount = animalCount[ax][ay];
                    // 물 bfs
                    waterBfs();
                }
                animalQueue.pop();
                if (map[ax][ay] == '*') continue;
                for (int k = 0; k < 4; k++) {
                    int nax = ax + dx[k];
                    int nay = ay + dy[k];
                    if (nax < 1 || nay < 1 || nax > r || nay > c) continue;
                    if (animalVisited[nax][nay]) continue;
                    // 물을 먼저 뿌렸기 때문에 같은 Count 에서는 animal 이 움직일 수 있음
                    if (map[nax][nay] == '*' && animalCount[nax][nay] != waterCount[nax][nay]) continue;
                    else if (map[nax][nay] == 'X') continue;
                    else if (map[nax][nay] == '.') map[nax][nay] = 'S';
                    animalVisited[nax][nay] = true;
                    animalCount[nax][nay] = animalCount[ax][ay] + 1;
                    animalQueue.push(make_pair(nax, nay));
                }
            }
        }
        void printWater() {
            cout << "===========printWater============" << endl;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    cout << waterCount[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        void printAnimal() {
            cout << "===========printAnimal===========" << endl;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    cout << animalCount[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        void printMap() {
            cout << "============printMap=============" << endl;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    cout << map[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        void printAns() {
            if (animalCount[posx][posy] == 0) {
                cout << "KAKTUS" << endl;
            } else {
                cout << animalCount[posx][posy] << endl;
            }
        }
        void solve() {
            bfs();
            printAns();
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
    return 0;
}
