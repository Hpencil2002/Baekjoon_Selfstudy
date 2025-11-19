#include <iostream>
#include <algorithm>
using namespace std;

int strong[21];
int pleasure[21];
int dp[101];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> strong[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> pleasure[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 100; j >= strong[i]; j--) {
            dp[j] = max(dp[j], dp[j - strong[i]] + pleasure[i]);
        }
    }

    cout << dp[99];

    return 0;
}