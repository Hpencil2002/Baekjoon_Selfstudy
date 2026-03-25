#include <iostream>
#include <cmath>
using namespace std;

int N;
int A, B;
int L;
int arr[21];
int dp[21][21][21];

int solve(int a, int b, int index) {
    if (index == L) {
        return 0;
    }

    if (dp[a][b][index]) {
        return dp[a][b][index];
    }

    int use1 = abs(arr[index] - a) + solve(arr[index], b, index + 1);
    int use2 = abs(arr[index] - b) + solve(a, arr[index], index + 1);
    dp[a][b][index] = min(use1, use2);

    return dp[a][b][index];
}

int main() {
    cin >> N;
    cin >> A >> B;
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> arr[i];
    }

    cout << solve(A, B, 0);

    return 0;
}