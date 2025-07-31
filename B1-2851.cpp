#include <iostream>
using namespace std;

int main() {
    int mushroom[10];
    for (int i = 0; i < 10; i++) {
        cin >> mushroom[i];
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        int sum = ans + mushroom[i];

        if (sum >= 100) {
            if (sum - 100 <= 100 - ans) {
                cout << sum;
            }
            else {
                cout << ans;
            }

            return 0;
        }

        ans = sum;
    }

    cout << ans;

    return 0;
}