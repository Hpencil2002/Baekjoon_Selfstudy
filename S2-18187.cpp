#include <iostream>
using namespace std;

int N;
int dp[105];

int main() {
    cin >> N;

    dp[1] = 2;
    dp[2] = 4;

    int add = 3;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i -1] + add;

        if (i % 3 != 0) {
            add += 1;
        }
    }

    cout << dp[N];

    return 0;
}