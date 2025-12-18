#include <iostream>
using namespace std;

int n;
long long dp[65][10];

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    while (T--) {
        cin >> n;

        long long ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += dp[n][i];
        }

        cout << ans << "\n";
    }

    return 0;
}