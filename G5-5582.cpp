#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str1, str2;
vector<vector<int>> dp;
int ans;

int main() {
    cin >> str1 >> str2;
    dp = vector<vector<int>>(str2.length(), vector<int>(str1.length(), 0));

    for (int i = 0; i < str2.length(); i++) {
        for (int j = 0; j < str1.length(); j++) {
            if (str2[i] == str1[j]) {
                dp[i][j] = 1;
                if (i >= 1 && j >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                }

                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans;

    return 0;
}