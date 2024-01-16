#include <iostream>
using namespace std;

int peo[101][15];

int main() {
    int t, k, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> k >> n;

        for (int j = 0; j <= k; j++) {
            for (int h = 1; h <= n; h++) {
                if (j == 0) {
                    peo[0][h] = h;
                }
                else if (h == 1) {
                    peo[j][1] = 1;
                }
                else {
                    peo[j][h] = peo[j][h - 1] + peo[j - 1][h];
                }
            }
        }
        cout << peo[k][n] << "\n";
    }

    return 0;
}