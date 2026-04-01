#include <iostream>
using namespace std;

int m, n;

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> m >> n;

        int i = 0, j = 0;
        cout << "1\n";

        while (true) {
            cout << '(' << i << ',' << j << ")\n";

            if (i % 2) {
                j -= 1;
            }
            else {
                j += 1;
            }

            if (j >= n || j < 1) {
                i += 1;

                if (i % 2) {
                    j -= 1;
                }
                else {
                    j += 1;
                }
            }

            if (i == m) {
                break;
            }
        }

        for (int d = m - 1; d > 0; d--) {
            cout << '(' << d << ',' << "0)\n";
        }
    }

    return 0;
}