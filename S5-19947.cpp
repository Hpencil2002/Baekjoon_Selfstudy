#include <iostream>
#include <algorithm>
using namespace std;

int year[3] = { 1, 3, 5 };
double rate[3] = { 1.05, 1.20, 1.35 };
int dp[11];

int main() {
    int H, Y;
    cin >> H >> Y;

    dp[0] = H;
    for (int i = 1; i <= Y; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - year[j] < 0) {
                continue;
            }

            dp[i] = max(dp[i], (int)(dp[i - year[j]] * rate[j]));
        }
    }

    cout << dp[Y];

    return 0;
}