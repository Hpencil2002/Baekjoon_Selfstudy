#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str1, str2;
vector<vector<int>> dp;

int main() {
    cin >> str1 >> str2;
    str1 = "0" + str1;
    str2 = "0" + str2;

    dp.resize(str2.size(), vector<int>(str1.size()));

    for (int i = 0; i < str2.size(); i++) {
        for (int j = 0; j < str1.size(); j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (str1[j] == str2[i]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[str2.size() - 1][str1.size() - 1];

    return 0;
}