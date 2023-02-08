#include <iostream>
#define endl '\n'
using namespace std;

int cache[21][21][21];

int go(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    int& ret = cache[a][b][c];
    if (ret != 0) return ret;
    else if (a > 20 || b > 20 || c > 20) {
        ret = go(20, 20, 20);
        return ret;
    }
    else if (a < b && b < c) {
        ret = go(a, b, c-1) + go(a, b-1, c-1) - go(a, b-1, c);
        return ret;
    }
    else {
        ret = go(a-1, b, c) + go(a-1, b-1, c) + go(a-1, b, c-1) - go(a-1, b-1, c-1);
        return ret;
    }
}

void printCache() {
    for (int i = 0; i <= 20; i ++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                cout << cache[i][j][k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        if (a <= 0 || b <= 0 || c <= 0) {
            cout << 1 << endl;
            continue;
        }
        if (a > 20 || b > 20 || c > 20) {
            a = 20, b = 20, c = 20;
        }
        go(a, b, c);
        cout << cache[a][b][c] << endl;
    }
}
