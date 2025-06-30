#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N < 3) {
        cout << 4;
    }

    for (int i = 2; i < N; i++) {
        if (N <= i * i) {
            cout << (i - 1) * 4;
            break;
        }
        else if (N <= i * (i + 1)) {
            cout << (i - 1) * 4 + 2;
            break;
        }
    }

    return 0;
}