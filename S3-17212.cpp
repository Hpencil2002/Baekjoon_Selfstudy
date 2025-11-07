#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[100001] = { 0, };
    for (int i = 1; i < 100001; i++) {
        dp[i] = dp[i - 1];

        if (i > 1) {
            dp[i] = min(dp[i], dp[i - 2]);
        }
        if (i > 4) {
            dp[i] = min(dp[i], dp[i - 5]);
        }
        if (i > 6) {
            dp[i] = min(dp[i], dp[i - 7]);
        }

        dp[i] += 1;
    }

    cout << dp[N];

    return 0;
}