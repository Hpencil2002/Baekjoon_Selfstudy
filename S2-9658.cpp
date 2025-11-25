#include <iostream>
using namespace std;

int N;
int dp[1005] = { 0, };

int main() {
    cin >> N;

    dp[1] = dp[3] = 0;
    dp[2] = dp[4] = dp[5] = 1;
    for (int i = 6; i <= N; i++) {
        if (dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1) {
            dp[i] = 0;
        }
        else {
            dp[i] = 1;
        }
    }

    if (dp[N] == 1) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }

    return 0;
}