#include <iostream>
using namespace std;

#define mod 1000000007

int D;
long long arr[8];
long long dp[8];

int main() {
    cin >> D;

    dp[0] = 1;
    while (D--) {
        arr[0] = dp[1] + dp[2];
        arr[1] = dp[0] + dp[2] + dp[3];
        arr[2] = dp[0] + dp[1] + dp[3] + dp[4];
        arr[3] = dp[1] + dp[2] + dp[4] + dp[5];
        arr[4] = dp[2] + dp[3] + dp[5] + dp[6];
        arr[5] = dp[3] + dp[4] + dp[7];
        arr[6] = dp[4] + dp[7];
        arr[7] = dp[5] + dp[6];

        for (int i = 0; i < 8; i++) {
            dp[i] = arr[i] % mod;
        }
    }

    cout << dp[0];

    return 0;
}