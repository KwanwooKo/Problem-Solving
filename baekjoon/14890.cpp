#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
int board[101][101];
bool solve(vector<int> &d, int N, int L) {
    bool check[101];
    memset(check, false, sizeof(check));
    
    int crit = d[0];
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (crit == d[i]) {
            if (check[i] == false)
                count++;
        }
        else if (crit - d[i] >= 2 || d[i] - crit >= 2)
            return false;
        else if (crit < d[i]) {
            if (count < L)
                return false;
            for (int k = i - L; k < i; k++) {
                if (check[k])
                    return false;
                check[k] = true;
            }
            crit = d[i];
            count = 1;
        }
        else if (crit > d[i]) {
            int tmp = d[i];
            count = 1;
            for (int j = i + 1; j < N; j++) {
                if (check[j])
                    return false;
                if (tmp != d[j])
                    break;
                count++;
            }
            if (count < L)
                return false;
            int index = i;
            for (int k = 0; k < L; k++) {
                check[index++] = true;
            }
            count = 0;
            crit = d[i];
        }
    }
    return true;
}
int main(void) {
    int N, L, ans = 0;
    cin >> N >> L;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        vector<int> d;
        for (int j = 1; j <= N; j++) {
            d.push_back(board[i][j]);
        }
        if (solve(d, N, L)) {
            ans++;
        }
    }
    
    for (int j = 1; j <= N; j++) {
        vector<int> d;
        for (int i = 1; i <= N; i++) {
            d.push_back(board[i][j]);
        }
        if (solve(d, N, L)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

