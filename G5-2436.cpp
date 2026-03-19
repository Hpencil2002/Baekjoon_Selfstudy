#include <iostream>
#include <cmath>
using namespace std;

long long gcd, lcm;
long long A, B;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }

    return GCD(b, a % b);
}

int main() {
    cin >> gcd >> lcm;

    long long div = lcm / gcd;
    for (int i = 1; i <= sqrt(div); i++) {
        if (div % i == 0) {
            long long a = i;
            long long b = div / i;

            if (GCD(a, b) == 1) {
                A = a;
                B = b;
            }
        }
    }

    cout << A * gcd << ' ' << B * gcd;

    return 0;
}