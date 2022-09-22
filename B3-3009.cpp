#include <iostream>
using namespace std;

int main() {
    int x[3], y[3], x_check[3], y_check[3];
    int ans_x, ans_y;
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
        x_check[i] = 1;
        y_check[i] = 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (x[i] == x[j]) {
                x_check[i] += 1;
                x_check[j] += 1;
            }
            if (y[i] == y[j]) {
                y_check[i] += 1;
                y_check[j] += 1;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (x_check[i] != 2) {
            ans_x = x[i];
        }
        if (y_check[i] != 2) {
            ans_y = y[i];
        }
    }

    cout << ans_x << " " << ans_y << "\n";

    return 0;
}