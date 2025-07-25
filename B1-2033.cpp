#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long tmp = 10;
    while (N >= tmp) {
        N % tmp >= tmp / 2 ? N = ((long long)((int)N / tmp) + 1) * tmp : N = ((long long)(int)N / tmp) * tmp;
        tmp *= 10;
    }

    cout << N;

    return 0;
}