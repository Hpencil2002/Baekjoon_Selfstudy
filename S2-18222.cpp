#include <iostream>
#include <string>
using namespace std;

long long k, t = 1;
long long cnt;

int main() {
    cin >> k;
    while ((t << 1) < k) {
        t <<= 1;
    }

    while (k > 2) {
        k -= t;
        cnt += 1;

        while (k <= t) {
            t >>= 1;
        }
    }

    if (k == 1) {
        cout << cnt % 2;
    }
    else {
        cout << (cnt + 1) % 2;
    }

    return 0;
}