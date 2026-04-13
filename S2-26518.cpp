#include <iostream>
#include <cmath>
using namespace std;

long long b, c, a1, a2;
double ans;

int main() {
    cin >> b >> c >> a1 >> a2;

    ans = (b + sqrt(1.0 * b * b + 4.0 * c)) / 2.0;

    cout << fixed;
    cout.precision(20);
    cout << ans;

    return 0;
}