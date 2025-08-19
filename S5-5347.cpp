#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;

        long long tmp = gcd(a, b);
        cout << tmp * (a / tmp) * (b / tmp) << "\n";
    }

    return 0;
}