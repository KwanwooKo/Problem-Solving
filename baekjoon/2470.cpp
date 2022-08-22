#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)2e9 + 1
using namespace std;
typedef long long ll;
class BOJ2470 {
private:
    int n, front, back, ansFront, ansBack;
    vector<int> arr;
public:
    BOJ2470() {
        cin >> n;
        front = 0, back = n - 1;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
    }
    void print() {
        cout << ansFront << ' ' << ansBack << endl;
    }
    void solve() {
        int memoSum = INF;
        while (front < back) {
            int sum = arr[front] + arr[back];
            if (sum == 0) {
                ansFront = arr[front];
                ansBack = arr[back];
                break;
            } else if (sum < 0) {
                if (abs(sum) < abs(memoSum)) {
                    memoSum = sum;
                    ansFront = arr[front];
                    ansBack = arr[back];
                }
                front++;
            } else {
                if (abs(sum) < abs(memoSum)) {
                    memoSum = sum;
                    ansFront = arr[front];
                    ansBack = arr[back];
                }
                back--;
            }
        }
        print();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2470 boj;
    boj.solve();

    return 0;
}