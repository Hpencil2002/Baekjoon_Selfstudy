#include <iostream>
using namespace std;

#define mod 1000000009

int n, m;
int dp[1001][1001];

int main() {
    int T;
    cin >> T;

    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    for (int i = 2; i < 1001; i++) {
        for (int j = 1; j < 1001; j++) {
            for (int k = 1; k < 4; k++) {
                if (j - k <= 0) {
                    continue;
                }

                dp[j][i] += dp[j - k][i - 1];
                dp[j][i] %= mod;
            }
        }
    }

    while (T--) {
        cin >> n >> m;

        cout << dp[n][m] << "\n";
    }

    return 0;
}