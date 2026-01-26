#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001][1001];

int solve(int cur, int prev) {
    int res = 0;

    if (dp[cur][prev] != -1) {
        return dp[cur][prev];
    }

    for (int i = cur; i < N; i++) {
        if (prev > arr[i]) {
            res = max(res, solve(i, arr[i]) + arr[i]);
        }
    }

    dp[cur][prev] = res;

    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    fill(&dp[0][0], &dp[1000][1000], -1);

    cout << solve(0, 1001);

    return 0;
}