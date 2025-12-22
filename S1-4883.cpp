#include <iostream>
#include <algorithm>
using namespace std;

int N;
int graph[100010][3];
int dp[100010][3];

int main() {
    int cnt = 1;

    while (true) {
        cin >> N;
        if (N == 0) {
            return 0;
        }

        fill(&graph[0][0], &graph[100009][3], 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> graph[i][j];
            }
        }

        dp[0][0] = INT32_MAX;
        dp[0][1] = graph[0][1];
        dp[0][2] = graph[0][1] + graph[0][2];

        for (int i = 1; i < N; i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
            dp[i][1] = min({ dp[i - 1][0], dp[i - 1][1], dp[i -1][2], dp[i][0] }) + graph[i][1];
            dp[i][2] = min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] }) + graph[i][2];
        }

        cout << cnt << ". " << dp[N -1][1] << "\n";

        cnt += 1;
    }
}