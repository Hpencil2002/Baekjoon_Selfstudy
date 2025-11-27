#include <iostream>
using namespace std;


int main() {
    long long S, K;
    cin >> S >> K;

    long long ans = 1;
    long long tmp1, tmp2;

    tmp1 = S / K;
    tmp2 = S % K;

    for (int i = 0; i < K; i++) {
        if (tmp2 > 0) {
            ans *= (tmp1 + 1);
            tmp2 -= 1;
        }
        else {
            ans *= tmp1;
        }
    }

    cout << ans;

    return 0;
}