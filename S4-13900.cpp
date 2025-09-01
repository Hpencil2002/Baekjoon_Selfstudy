#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int num[100000];
    long long sum[100001];
    sum[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        sum[i + 1] = sum[i] + num[i];
    }

    long long ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += num[i] * (sum[N] - sum[i + 1]);
    }

    cout << ans;

    return 0;
}