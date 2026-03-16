#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long dp[31][31];

long long dfs(int w, int h) {
    if (h == -1) {
        return 0;
    }
    if (w == 0) {
        return 1;
    }

    long long& res = dp[w][h];
    if (res) {
        return dp[w][h];
    }

    res = dfs(w - 1, h + 1) + dfs(w, h - 1);

    return res;
}

int main() {
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        cout << dfs(N, 0) << "\n";
    }

    return 0;
}