#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int R = N * 4 - 3;
    int C = N * 4 - 3;
    int center = N * 2 - 2;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (max(abs(r - center), abs(c - center)) & 1) {
                cout << ' ';
            }
            else {
                cout << '*';
            }
        }

        cout << "\n";
    }

    return 0;
}