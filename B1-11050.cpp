#include <iostream>
using namespace std;

int fac(int a);

int main() {
    int n, k;
    cin >> n >> k;

    cout << fac(n) / (fac(k) * fac(n - k)) << "\n";

    return 0;
}

int fac(int a) {
    if (a == 1 || a == 0) {
        return 1;
    }
    else {
        return a * fac(a - 1);
    }
}