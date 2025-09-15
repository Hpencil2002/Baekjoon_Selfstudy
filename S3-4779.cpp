#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void solve(int n) {
    int size = pow(3, n - 1);

    if (n == 0) {
        cout << "-";
        return;
    }

    solve(n - 1);

    for (int i = 0; i < size; i++) {
        cout << " ";
    }

    solve(n - 1);
}

int main() {
    int N;

    while (cin >> N) {
        solve(N);
        cout << "\n";
    }

    return 0;
}