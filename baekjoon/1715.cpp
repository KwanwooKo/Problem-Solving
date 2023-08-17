#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int main(void) {
    int n, ans = 0, count = 0;
    int first, second;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (!pq.empty()) {
        int num = pq.top();
        pq.pop();
        count++;

        if (count == 1) {
            first = num;
        }
        else if (count == 2) {
            second = num;
            count = 0;
            ans += (first + second);
            pq.push(first + second);
            first = 0, second = 0;
        }
    }

    cout << ans << endl;


    return 0;
}
