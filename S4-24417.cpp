#include <iostream>
using namespace std;

#define mod 1000000007

int n;

int fib1(int num) {
    long long res;

    long long n1 = 1;
    long long n2 = 1;
    for (int i = 3; i <= num; i++) {
        res = (n1 + n2) % mod;
        n1 = n2;
        n2 = res;
    }

    return res;
}

int main() {
    cin >> n;

    cout << fib1(n) << ' ' << n - 2;

    return 0;
}