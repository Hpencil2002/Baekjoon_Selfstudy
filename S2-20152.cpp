#include <iostream>
#include <algorithm>
using namespace std;

int H, N;
long long dp[32][32];

int main() {
    cin >> H >> N;

    if (H < N) {
        swap(H, N);
    }
    else if (H == N) {
        cout << 1;

        return 0;
    }

    dp[N][N] = 1;
    for (int i = N; i <= H; i++) {
        for (int j = N + 1; j <= H; j++) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = (i > N ? dp[i - 1][j] : 0) + (j > N ? dp[i][j - 1] : 0);
            }
        }
    }

    cout << dp[H][H];

    return 0;
}