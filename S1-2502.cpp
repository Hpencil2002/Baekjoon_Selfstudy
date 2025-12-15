#include <iostream>
using namespace std;

int D, K;
int A[35];
int B[35];

int main() {
    cin >> D >> K;

    A[1] = 1;
    A[2] = 0;
    B[1] = 0;
    B[2] = 1;

    for (int i = 3; i <= D; i++) {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }

    for (int i = 1; i <= K; i++) {
        int spare = K - (A[D] * i);

        if (spare % B[D] == 0) {
            cout << i << "\n" << spare / B[D];

            return 0;
        }
    }
}