#include <iostream>
using namespace std;

int max_fibo(int n) {
    int fib0 = 0;
    int fib1 = 1;

    if (n <= 1) {
        return n;
    }

    while (true) {
        int fib2 = fib1 + fib0;

        if (fib2 == n) {
            return fib2;
        }
        else if (fib2 > n) {
            return fib1;
        }

        fib0 = fib1;
        fib1 = fib2;
    }
}

void solve(int n) {
    if (n == 1) {
        cout << "1";

        return;
    }

    int res = max_fibo(n);
    if (n > res) {
        solve(n - res);
        cout << ' ';
    }

    cout << res;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        solve(n);

        cout << "\n";
    }

    return 0;
}