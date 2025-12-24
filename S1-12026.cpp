#include <iostream>
#include <algorithm>
using namespace std;

int N;
char arr[1001];
int dp[1001];

bool check(char cur, char next) {
    if (cur == 'B' && next == 'O') {
        return true;
    }
    if (cur == 'O' && next == 'J') {
        return true;
    }
    if (cur == 'J' && next == 'B') {
        return true;
    }

    return false;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = 987654321;
    }

    dp[1] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (!check(arr[i], arr[j])) {
                continue;
            }

            dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
        }
    }

    cout << (dp[N] == 987654321 ? -1 : dp[N]);

    return 0;
}