#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main(void) {
    int n, ans = 0;
    cin >> n;
    bool is_zero = false;
    priority_queue<int, vector<int>, less<>> pq_minus;
    priority_queue<int> pq_plus;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < 0) {
            pq_minus.push(num);
        }
        else if (num == 0) {
            is_zero = true;
        }
        else if (num > 0) {
            pq_plus.push(num);
        }
    }
    
    if (pq_minus.size() % 2 == 1) {
        int minus_top = pq_minus.top();
        pq_minus.pop();
        if (!is_zero)
            ans += minus_top;
    }
    int first, second, count = 0;
    while (!pq_minus.empty()) {
        int minus_top = pq_minus.top();
        pq_minus.pop();
        if (count == 0) {
            first = minus_top;            
            count++;
        }
        else if (count == 1) {
            second = minus_top;
            count = 0;
            ans += (first * second);
        }
    }
    count = 0;
    while (!pq_plus.empty()) {
        int plus_top = pq_plus.top();
        pq_plus.pop();
        if (count == 0) {
            first = plus_top;
            count++;
        }
        else if (count == 1) {
            second = plus_top;
            count = 0;
            ans += max(first + second, first * second);
        }
    }
    if (count == 1) {
        ans += first;
    }
    cout << ans << endl;
    return 0;
}
