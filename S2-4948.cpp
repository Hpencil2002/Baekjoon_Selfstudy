#include <iostream>
using namespace std;

bool isPrime(long long num) {
    if (num <= 1) {
        return false;
    }

    if (num == 2 || num == 3) {
        return true;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            return 0;
        }

        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (isPrime(i)) {
                ans += 1;
            }
        }

        cout << ans << "\n";
    }
}