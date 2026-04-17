#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;

    if (N & 1) {
        int mid = (N + 1) / 2;

        cout << mid;
        for (int i = N; i > mid; i--) {
            cout << ' ' << i << ' ' << i - mid;
        }
    }
    else {
        int mid = N / 2;

        for (int i = N; i > mid; i--) {
            cout << i - mid << ' ' << i << ' ';
        }
    }

    return 0;
}