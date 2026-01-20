#include <iostream>
using namespace std;

int N;
int L, R;

int main() {
    cin >> N;

    L = 1;
    R = N;
    while (L < R) {
        cout << L << ' ' << R << ' ';

        L += 1;
        R -= 1;
    }

    if (L == R) {
        cout << L;
    }

    return 0;
}