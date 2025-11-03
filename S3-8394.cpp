#include <iostream>
#include <cstring>
using namespace std;

int dp[10000002];

int main() {
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
    }

    cout << dp[n];

    return 0;
}