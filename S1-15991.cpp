#include <iostream>
using namespace std;

#define mod 1000000009

int n;
long long dp[100001] = { 0, 1, 2, 2, 3, 3, 6, };

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n;

        for (int i = 7; i <= n; i++) {
            dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % mod;
        }

        cout << dp[n] << "\n";
    }

    return 0;
}