#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[11] = { 0, };
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + (i - 1);
    }

    cout << dp[N];

    return 0;
}