#include <iostream>
using namespace std;

bool prime[10000001];

int main() {
    int K;
    cin >> K;

    int ans = 2;
    for (int i = 1; i < K; i++) {
        if (prime[ans]) {
            continue;
        }

        int n = 1;
        while (ans * n <= 10000000) {
            prime[ans * n] = true;
            n += 1;
        }

        ans += 1;
        while (prime[ans]) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}