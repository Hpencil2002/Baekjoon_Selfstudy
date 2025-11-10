#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int* tmp = a;
    a = b;
    b = tmp;
}

int main() {
    while (true) {
        int n, k;
        cin >> n >> k;

        if (n == 0 && k == 0) {
            return 0;
        }

        int r = n - k;
        if (r > k) {
            swap(r, k);
        }

        int div = 1;
        long long ans = 1;
        for (int i = n; i >= n - r + 1; i--) {
            ans *= i;
            ans /= div;
            div += 1;
        }

        cout << ans << "\n";
    }
}