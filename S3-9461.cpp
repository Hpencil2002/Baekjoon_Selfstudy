#include <iostream>
using namespace std;

long long arr[101] = {0, 1, 1, };
long long dp(int N);

int main() {
    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << dp(N) << "\n";
    }

    return 0;
}

long long dp(int N) {
    if (N < 3) {
        return arr[N];
    }
    else if (arr[N] == 0) {
        arr[N] = dp(N - 2) + dp(N - 3);
    }

    return arr[N];
}