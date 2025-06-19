#include <iostream>
using namespace std;

int X;
int ans = 0;

int main() {
    cin >> X;

    while (X > 0) {
        if (X % 2 == 1) {
            ans += 1;
        }
        X /= 2;
    }

    cout << ans;

    return 0;
}