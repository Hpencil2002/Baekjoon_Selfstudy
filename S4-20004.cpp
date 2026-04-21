#include <iostream>
using namespace std;

int A;
int dp[32][32];

int main() {
    cin >> A;

    for (int i = 2; i <= 31; i++) {
        for (int j = 1; j <= 31; j++) {
            if (i + 1 >= j) {
                dp[i][j] = 0;
            }
            else {
                int check = 1;

                for (int k = 1; k <= i; k++) {
                    if (dp[i][j - k] == 1) {
                        check = 0;
                    }
                }

                dp[i][j] = check;
            }
        }
    }

    cout << 1 << "\n";
    for (int i = 2; i <= A; i++) {
        if (dp[i][31] == 1) {
            cout << i << "\n";
        }
    }

    return 0;
}