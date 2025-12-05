#include <iostream>
#include <string>
using namespace std;

long long int gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long ans = gcd(a, b);
    for (int i = 0; i < ans; i++) {
        cout << 1;
    }

    return 0;
}