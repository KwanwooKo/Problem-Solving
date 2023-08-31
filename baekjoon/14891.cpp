#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define endl '\n'
#define CLOCKWISE 1
#define NONCLOCKWISE (-1)
using namespace std;
vector<string> gears;
vector<string> snapshot;
bool check[4];
void clockwise(int index) {
    string &s = gears[index];
    char tmp = s[0];
    for (int i = 1; i < 8; i++) {
        swap(s[i], tmp);
    }
    s[0] = tmp;
}
void non_clockwise(int index) {
    string &s = gears[index];
    char tmp = s[0];
    for (int i = 0; i < 7; i++) {
        s[i] = s[i + 1];
    }
    s[7] = tmp;
}
void spin_gear(int index, int dir) {
    if (dir == CLOCKWISE) {
        clockwise(index);
    }
    else {
        non_clockwise(index);
    }
}

void go(int cur, int cur_dir, bool spin) {
    if (!spin) {
        return;
    }
    if (check[cur]){
        return;}
    check[cur] = true;
    spin_gear(cur, cur_dir);

    if (cur + 1 < 4) {
        int next = cur + 1;
        if (snapshot[cur][2] == snapshot[next][6]) {
            go(next, cur_dir, false);
        }
        else {
            go(next, cur_dir * (-1), true);
        }
    }
    if (cur - 1 >= 0) {
        int next = cur - 1;
        if (snapshot[next][2] == snapshot[cur][6]) {
            go(next, cur_dir, false);
        }
        else {
            go(next, cur_dir * (-1), true);
        }
    }
}
void print_gears() {
    for (int i = 0; i < 4; i++) {
        cout << gears[i] << endl;
    }
    cout << endl;
}
void init() {
    memset(check, false, sizeof(check));
    snapshot.clear();
    for (string s: gears) {
        snapshot.push_back(s);
    }
}
int main(void) {

    int k;

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        gears.push_back(s);
        snapshot.push_back(s);
    }
    cin >> k;
    while (k--) {
        init();
        int cur, dir;
        cin >> cur >> dir;
        cur--;
        go(cur, dir, true);
//        print_gears();
    }
    int ans = 0;
    if (gears[0][0] == '1') {
        ans += 1;
    }
    if (gears[1][0] == '1') {
        ans += 2;
    }
    if (gears[2][0] == '1') {
        ans += 4;
    }
    if (gears[3][0] == '1') {
        ans += 8;
    }
//    print_gears();
    cout << ans << endl;
    return 0;
}
