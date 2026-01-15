#include <iostream>
using namespace std;

int T;
int a, b;
int ans;

int gcd(int A, int B) {
    return A % B ? gcd(B, A % B) : B;
}

int solve(int A, int B) {
    int i = 1;
    int GCD;

    while (A != 1) {
        i = (B % A == 0) ? (B / A) : (B / A + 1);
        A = A * i - B;
        B *= i;

        GCD = gcd(A, B);
        A /= GCD;
        B /= GCD;
    }

    return B;
}

int main() {
    cin >> T;

    while (T--) {
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }

    return 0;
}