#include <iostream>
using namespace std;

int n;
int cross[100002];
long long Left[100002];
long long Right[100002];
long long minDist = 1e18;
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cross[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> Left[i];
        Left[i] += Left[i - 1];
    }
    for (int i = 1; i < n; i++) {
        cin >> Right[i];
        Right[i] += Right[i - 1];
    }

    for (int i = 0; i < n; i++) {
        long long tmp = Left[i] + cross[i] + Right[n- 1] - Right[i];

        if (minDist > tmp) {
            minDist = tmp;
            ans = i + 1;
        }
    }

    cout << ans << ' ' << minDist;

    return 0;
}