#include <iostream>
using namespace std;

#define mod 1000000009

int N;

int main() {
    cin >> N;

    if (N == 1) {
        cout << 0;
    }
    else if (N == 2) {
        cout << 2;
    }
    else {
        long long ans = 2;

        for (int i = 2; i < N; i++) {
            ans *= 3;
            ans %= mod;
        }

        cout << ans;
    }

    return 0;
}