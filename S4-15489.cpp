#include <iostream>
using namespace std;

int main() {
    int R, C, W;
    cin >> R >> C >> W;

    int ans = 0;
    int dp[31][31] = { 0, };

    dp[1][1] = 1;
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i < W; i++) {
        for (int j = 0; j <= i; j++) {
            ans += dp[R + i][C + j];
        }
    }

    cout << ans;

    return 0;
}