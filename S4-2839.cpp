#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x, y;
    x = n / 5;
    while (1) {
        if (x < 0) {
            cout << "-1";
            return 0;
        }

        if ((n - (5 * x)) % 3 == 0) {
            y = (n - (5 * x)) / 3;
            break;
        }
        x -= 1;
    }

    cout << x + y;

    return 0;
}