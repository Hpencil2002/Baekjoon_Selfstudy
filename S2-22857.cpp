#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[1000001];
int dp[50001][101];
int ans;

int solve(int x, int cnt, int len) {
    if (x <= 0 || cnt > K) {
        return len;
    }
    if (dp[x][cnt] != 0) {
        return dp[x][cnt];
    }

    int val = 0;
    if (arr[x] % 2 == 0) {
        val = solve(x - 1, cnt, len + 1);
    }
    else if (cnt < K) {
        val = solve(x - 1, cnt + 1, len);
    }
    else if (cnt == K) {
        return len;
    }

    return dp[x][cnt] = val;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = N; i >= 1; i--) {
        for (int j = 0; j <= K; j++) {
            if (arr[i] % 2 == 0) {
                ans = max(ans, solve(i, j, 0));
            }
        }
    }

    cout << ans;

    return 0;
}