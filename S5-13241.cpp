#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    long long int A, B;
    cin >> A >> B;

    long long int ans = A * B / gcd(A, B);
    cout << ans;

    return 0;
}