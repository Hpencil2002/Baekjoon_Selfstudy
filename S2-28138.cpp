#include <iostream>
using namespace std;

long long N, R;
long long ans;

int main() {
    cin >> N >> R;
    N -= R;

    long long i = 1;
    for (; i * i < N; i++) {
        if (N % i) {
            continue;
        }

        if (i > R) {
            ans += i;
        }
        if (N / i > R) {
            ans += N / i;
        }
    }

    if (i * i == N && i > R) {
        ans += i;
    }

    cout << ans;

    return 0;
}