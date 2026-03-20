#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, T;
int dp[10001];
vector<pair<int, int>> vc;

int main() {
    cin >> N >> T;

    vc = vector<pair<int, int>>(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> vc[i].first >> vc[i].second;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = T; j >= vc[i].first; j--) {
            dp[j] = max(dp[j], dp[j - vc[i].first] + vc[i].second);
        }
    }

    cout << dp[T];

    return 0;
}