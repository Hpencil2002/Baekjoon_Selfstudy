#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[301][301];
int dp[301][301];

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        }
    }

    cout << dp[N][M];

    return 0;
}