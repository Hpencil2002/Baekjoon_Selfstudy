#include <iostream>
using namespace std;

int T;
int P, Q;
long long fib[10001];

int main() {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> P >> Q;

        fib[1] = 1;
        fib[2] = 1;
        for (int i = 3; i <= P; i++) {
            fib[i] = (fib[i - 1] + fib[i - 2]) % Q;
        }

        cout << "Case #" << t << ": " << fib[P] % Q << "\n";
    }

    return 0;
}