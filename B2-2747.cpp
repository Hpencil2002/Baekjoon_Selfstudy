#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int fib[46];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 46; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[N];

    return 0;
}