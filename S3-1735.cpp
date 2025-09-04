#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int E, F, G;
    E = (A * D + B * C);
    F = B * D;
    G = gcd(E, F);

    cout << E / G << ' ' << F / G;

    return 0;
}