#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int arr[2];
int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[num]++;
    }
    if (arr[0] > arr[1]) {
        cout << "Junhee is not cute!" << endl;
    }
    else {
        cout << "Junhee is cute!" << endl;
    }
    return 0;
}
