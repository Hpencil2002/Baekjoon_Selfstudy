#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i *= 10) {
        ans += N - i + 1;
    }

    cout << ans;

    return 0;
}