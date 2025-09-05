#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    int loc[1000];
    for (int i = 0; i < N; i++) {
        cin >> loc[i];
    }

    sort(loc, loc + N);

    int start = loc[0];
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (L <= loc[i] - start) {
            ans += 1;
            start = loc[i];
        }
    }

    cout << ans + 1;

    return 0;
}