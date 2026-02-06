#include <iostream>
using namespace std;

#define mod 1000000009

int n;
int dp[100001][2];

int main() {
    int T;
    cin >> T;

    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for (int i = 3; i <= 100000; i++) {
        dp[i][0] = ((dp[i - 1][1] + dp[i - 2][1]) % mod + dp[i - 3][1]) % mod;
        dp[i][1] = ((dp[i - 1][0] + dp[i - 2][0]) % mod + dp[i - 3][0]) % mod;
    }

    while (T--) {
        cin >> n;

        cout << dp[n][1] << ' ' << dp[n][0] << "\n";
    }

    return 0;
}