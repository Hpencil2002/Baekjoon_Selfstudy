#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long fib[117];
    fib[1] = 1;
    fib[2] = 1;
    fib[3] = 1;
    for (int i = 4; i < 117; i++) {
        fib[i] = fib[i -1] + fib[i - 3];
    }

    cout << fib[n];

    return 0;
}