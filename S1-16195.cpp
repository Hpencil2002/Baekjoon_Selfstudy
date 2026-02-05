#include <iostream>
using namespace std;

#define mod 1000000009

long long n, m;
long long ans;
long long dp[1001][1001];

int main() {
    int T;
    cin >> T;

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    for (int i = 4; i <= 1000; i++) {
        for (int j = 2; j <= i; j++) {
            dp[i][j] += (dp[i - 1][j - 1] % mod + dp[i - 2][j - 1] % mod + dp[i - 3][j - 1] % mod) % mod;
        }
    }

    while (T--) {
        cin >> n >> m;

        ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = (ans % mod + dp[n][i] % mod) % mod;
        }

        cout << ans << "\n";
    }

    return 0;
}