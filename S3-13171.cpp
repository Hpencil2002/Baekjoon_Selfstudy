#include <iostream>
using namespace std;

#define mod 1000000007

long long A, X;

long long solve(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    else {
        long long n = solve(a, b / 2);
        long long res = (n * n) % mod;

        if (b % 2 == 0) {
            return res;
        }
        else {
            return (res * a) % mod;
        }
    }
}

int main() {
    cin >> A >> X;

    cout << solve(A % mod, X);

    return 0;
}