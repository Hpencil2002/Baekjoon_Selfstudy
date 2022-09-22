#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        if (a > b && a > c) {
            if (pow(a, 2) == pow(b, 2) + pow(c, 2)) {
                cout << "right\n";
            }
            else {
                cout << "wrong\n";
            }
        }
        else if (b > a && b > c) {
            if (pow(b, 2) == pow(a, 2) + pow(c, 2)) {
                cout << "right\n";
            }
            else {
                cout << "wrong\n";
            }
        }
        else if (c > a && c > b) {
            if (pow(c, 2) == pow(a, 2) + pow(b, 2)) {
                cout << "right\n";
            }
            else {
                cout << "wrong\n";
            }
        }
    }

    return 0;
}