#include <iostream>
using namespace std;

long long dp[1000010];

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
        }

        cout << dp[n] % 1000000009 << "\n";
    }

    return 0;
}