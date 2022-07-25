#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum != 180) {
        cout << "Error" << endl;
        return 0;
    }
    else {
        if (a == b && b == c) {
            cout << "Equilateral" << endl;
        }
        else if (a != b && b != c && c != a) {
            cout << "Scalene" << endl;
        }
        else {
            cout << "Isosceles" << endl;
        }
    }
    return 0;
}