#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main() {
    int N, M;
    cin >> N >> M;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> arr[y][x];
            dp[y][x] = arr[y][x];
        }
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            dp[y][x] = arr[y][x] + max(dp[y - 1][x - 1], max(dp[y - 1][x], dp[y][x - 1]));
        }
    }

    cout << dp[N][M];

    return 0;
}