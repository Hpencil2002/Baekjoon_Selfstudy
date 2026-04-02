#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int s[100001];
int e[100001];
int peo[100001];
int dp[100001];

int solve(int n) {
    if (n >= N) {
        return 0;
    }

    int& res = dp[n];
    if (res != -1) {
        return res;
    }

    return res = max(peo[n] + solve(n + 2), solve(n + 1));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> peo[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0);

    return 0;
}