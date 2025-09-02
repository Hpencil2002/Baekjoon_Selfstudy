#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int a = 0;
    int b = N - 1;
    int c = 3 * N - 3;
    int d = 4 * N - 4;

    for (int i = 1; i < 2 * N; i++) {
        if (i == 1 || i == 2 * N - 1) {
            for (int j = a; j <= b; j++) {
                cout << '*';
            }
            for (int j = b + 1; j < c; j++) {
                cout << ' ';
            }
            for (int j = c; j <= d; j++) {
                cout << '*';
            }
        }
        else {
            for (int j = 0; j < a; j++) {
                cout << ' ';
            }
            cout << '*';

            for (int j = a + 1; j < b; j++) {
                cout << ' ';
            }
            cout << '*';

            for (int j = b + 1; j < c; j++) {
                cout << ' ';
            }
            if (b != c) {
                cout << '*';
            }

            for (int j = c + 1; j < d; j++) {
                cout << ' ';
            }
            cout << '*';
        }
        cout << "\n";

        if (i < N) {
            a += 1;
            b += 1;
            c -= 1;
            d -= 1;
        }
        else {
            a -= 1;
            b -= 1;
            c += 1;
            d += 1;
        }
    }

    return 0;
}