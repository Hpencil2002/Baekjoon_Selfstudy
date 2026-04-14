#include <iostream>
using namespace std;

long long N;
long long K = 1;

int main() {
    cin >> N;

    while (K < N) {
        K = K * 2 + 1;
    }

    if (K == N) {
        cout << 1 << "\n" << N;
    }
    else {
        cout << 2 << "\n" << (K ^ N) << "\n" << N;
    }

    return 0;
}