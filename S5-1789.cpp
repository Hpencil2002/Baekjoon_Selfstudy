#include <iostream>
using namespace std;

int main() {
    long long S;
    cin >> S;

    int ans = 0;
    while (S > 0) {
        ans += 1;
        S -= ans;
    }

    if (S < 0) {
        ans -= 1;
    }

    cout << ans;

    return 0;
}