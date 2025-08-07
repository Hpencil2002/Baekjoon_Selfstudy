#include <iostream>
using namespace std;

int main() {
    int money;
    cin >> money;

    int ans = 0;
    int coin[6] = { 500, 100, 50, 10, 5, 1 };
    int left = 1000 - money;

    for (int i = 0; i < 6; i++) {
        while (left >= coin[i]) {
            left -= coin[i];
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}