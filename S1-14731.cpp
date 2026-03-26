#include <iostream>
using namespace std;

long long mod = 1e9 + 7;
int N;
long long ans;

int main() {
    cin >> N;
    while (N--) {
        long long c, k;
        cin >> c >> k;

        if (k == 0) {
            continue;
        }

        c = (c * k) % mod;
        k -= 1;

        long long seq = 2;
        while (k) {
            if (k & 1) {
                c = (c * seq) % mod;
            }

            k >>= 1;
            seq = (seq * seq) % mod;
        }

        ans += c;
    }

    cout << ans % mod;

    return 0;
}