#include <iostream>
#include <algorithm>
using namespace std;

int ans;

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int N, S;
    cin >> N >> S;

    int cur;
    cin >> cur;

    ans = abs(S - cur);
    for (int i = 0; i < N - 1; i++) {
        S = cur;
        cin >> cur;
        ans = gcd(ans, abs(S - cur));
    }

    cout << ans;

    return 0;
}