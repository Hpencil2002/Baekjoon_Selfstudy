#include <iostream>
using namespace std;

int fac(int num) {
    if (num <= 1) {
        return 1;
    }
    else {
        return num * fac(num - 1);
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int denominator;
    int numerator;
    double ans;

    denominator = fac(N) / (fac(M) * fac(N - M));
    numerator = 0;

    for (int i = K; i <= M; i++) {
        int jimin = fac(M) / (fac(i) * fac(M - i));
        int lotto = fac(N - M) / (fac(M - i) * fac(N - 2 * M + i));

        numerator += jimin * lotto;
    }

    ans = double(numerator) / double(denominator);

    cout.precision(10);
    cout << ans;

    return 0;
}