#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int time_count[1001];
int cache[1001];
void print_array() {
    for (int i = 0; i < 10; i++) {
        cout << time_count[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << cache[i] << ' ';
    }
    cout << endl;
}
int main(void) {
    int start = -1, end = -1;
    int ans = -1;
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int s, e;
            cin >> s >> e;
            for (int l = s + 1; l <= e; l++) {
                time_count[l]++;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        cache[i] = cache[i - 1] + time_count[i];
    }

    for (int i = t; i <= 1000; i++) {
        int tmp = cache[i] - cache[i - t];
        if (ans < tmp) {
            ans = tmp;
            start = i - t;
            end = i;
        }
    }

   
    cout << start << ' ' << end << endl;
    return 0;
}
