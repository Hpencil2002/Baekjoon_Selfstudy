#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long ans = 0;
    for (long long i = 1; i < N; i++) {
        ans += i * N + i;
    }

    cout << ans;

    return 0;
}