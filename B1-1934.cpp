#include <iostream>
using namespace std;

int divide(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return divide(b, a % b);
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        if (A >= B) {
            cout << A * B / divide(A, B) << "\n";
        }
        else {
            cout << A * B / divide(B, A) << "\n";
        }
    }

    return 0;
}