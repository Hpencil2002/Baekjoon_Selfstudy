#include <iostream>
using namespace std;

int N, M, K;
int dp[16][16];
pair<int, int> pos;

int main() {
    cin >> N >> M >> K;
    pos = { -1, -1 };

    int num = 1;
    if (K != 0) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (num == K) {
                    pos = { i, j };
                }

                num += 1;
            }
        }
    }

    dp[1][1] = 1;
    if (K == 0) {
        for (int i = 1;  i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }

        cout << dp[N][M];
    }
    else {
        for (int i = 1; i <= pos.first; i++) {
            for (int j = 1; j <= pos.second; j++) {
                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }

        int tmp = dp[pos.first][pos.second];
        dp[pos.first][pos.second] = 1;

        for (int i = pos.first; i <= N; i++) {
            for (int j = pos.second; j <= M; j++) {
                if (i == pos.first && j == pos.second) {
                    continue;
                }

                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }

        cout << tmp * dp[N][M];
    }

    return 0;
}