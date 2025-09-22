#include <iostream>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int num = 1;
        int ans = 1;

        while (true) {
            if (num % n == 0) {
                break;
            }
            else {
                ans += 1;
                num = num * 10 + 1;
                num %= n;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}