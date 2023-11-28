#include <iostream>
using namespace std;

int main() {
    int t;
    int n;
    int fib[42][2];

    fib[0][0] = 1;
    fib[0][1] = 0;

    fib[1][0] = 0;
    fib[1][1] = 1;

    for (int i = 2; i < 42; i++) {
        fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
        fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
    }

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << fib[n][0] << " " << fib[n][1] << "\n";
    }

    return 0;
}