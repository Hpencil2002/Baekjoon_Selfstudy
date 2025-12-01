#include <iostream>
using namespace std;


int main() {
    long long N;
    cin >> N;

    long long ans = 1;
    for (int i = 1; i <= N; i++) {
        ans *= i;
        ans %= 10000000;

        while (ans % 10 == 0) {
            ans /= 10;
        }
    }

    cout << ans % 10;

    return 0;
}