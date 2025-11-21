#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> vc;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        vc.push_back(tmp);
    }

    int dp[2000] = { 0, };
    dp[0] = 1;

    int cnt = 1;
    for (int i = 1; i < vc.size(); i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (vc[j] > vc[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }

        cnt = max(cnt, dp[i]);
    }

    cout << N - cnt << "\n";

    return 0;
}