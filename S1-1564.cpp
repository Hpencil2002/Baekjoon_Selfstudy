#include <iostream>
using namespace std;

long long N;
long long ans = 1;

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        ans *= i;

        while (ans % 10 == 0) {
            ans /= 10;
        }

        ans %= 1000000000000;
    }

    printf("%05lld", ans % 100000);

    return 0;
}