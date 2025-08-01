#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double A, B, C, I, J, K;
    cin >> A >> B >> C >> I >> J >> K;

    double a = A / I;
    double b = B / J;
    double c = C / K;

    double ans = min(min(a, b), c);

    cout << fixed << setprecision(6) << A - ans * I << ' ' << B - ans * J << ' ' << C - ans * K;

    return 0;
}