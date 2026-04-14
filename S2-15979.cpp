#include <iostream>
#include <algorithm>
using namespace std;

int M, N;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    else if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    cin >> M >> N;
    if (N < 0) {
        N *= -1;
    }
    if (M < 0) {
        M *= -1;
    }

    cout << min(gcd(M, N), 2);

    return 0;
}