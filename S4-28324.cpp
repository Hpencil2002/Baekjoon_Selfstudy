#include <iostream>
#include <algorithm>
using namespace std;

long long arr[500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    long long tmp = 0;
    long long ans = 0;
    for (int i = N; i >= 1; i--) {
        tmp = min(tmp + 1, arr[i]);
        ans += tmp;
    }

    cout << ans;

    return 0;
}