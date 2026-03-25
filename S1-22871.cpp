#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N;
long long arr[5001];
long long dp[5001];

long long solve(int x) {
    if (x == N - 1) {
        return 0;
    }

    long long& res = dp[x];
    if (res != -1) {
        return res;
    }

    res = 1e10;
    for (int i = x + 1; i < N; i++) {
        res = min(res, max(solve(i), (i - x) * (1 + abs(arr[x] - arr[i]))));
    }

    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0);

    return 0;
}