#include <iostream>
#include <cmath>
using namespace std;

int N;
int ans;
int honey[100002];
int sums[100002];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> honey[i];
        sums[i] = sums[i - 1] + honey[i];
    }

    int beeFirst = 0, beeSecond = 0;
    int honeyFirst = 0, honeySecond = 0;
    int home;

    beeFirst = 1;
    home = N;
    for (int i = beeFirst + 1; i < home; i++) {
        honeyFirst = sums[home] - (honey[beeFirst] + honey[i]);
        honeySecond = sums[home] - sums[i];

        ans = max(ans, honeyFirst + honeySecond);
    }

    beeSecond = N;
    home = 1;
    for (int i = home + 1; i < beeSecond; i++) {
        honeyFirst = sums[i] - honey[i];
        honeySecond = sums[beeSecond] - (honey[beeSecond] + honey[i]);

        ans = max(ans, honeyFirst + honeySecond);
    }

    beeFirst = 1;
    beeSecond = N;
    for (int i = beeFirst + 1; i < beeSecond; i++) {
        honeyFirst = sums[i] - honey[beeFirst];
        honeySecond = sums[beeSecond] - (sums[i - 1] + honey[beeSecond]);

        ans = max(ans, honeyFirst + honeySecond);
    }

    cout << ans;

    return 0;
}