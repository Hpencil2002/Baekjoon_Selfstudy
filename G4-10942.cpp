#include <iostream>
using namespace std;

int N, M;
int arr[2001];
bool dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i][i] = true;
        if (i != 1 && arr[i - 1] == arr[i]) {
            dp[i - 1][i] = true;
        }
    }
    for (int i = 2; i <= N - 1; i++) {
        for (int j = 1; i + j <= N; j++) {
            if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1]) {
                dp[j][i + j] = true;
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;

        if (dp[S][E]) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }

    return 0;
}