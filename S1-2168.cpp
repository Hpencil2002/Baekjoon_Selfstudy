#include <iostream>
using namespace std;

int x, y;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin >> x >> y;

    if (gcd(x, y) == 1) {
        cout << x + y - 1;
    }
    else {
        cout << x + y - gcd(x, y);
    }

    return 0;
}