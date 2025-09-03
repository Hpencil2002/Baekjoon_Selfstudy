#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long pinary[91];
    pinary[0] = 0;
    pinary[1] = 1;
    pinary[2] = 1;
    for (int i = 3; i <= N; i++) {
        pinary[i] = pinary[i - 1] + pinary[i - 2];
    }

    cout << pinary[N];

    return 0;
}