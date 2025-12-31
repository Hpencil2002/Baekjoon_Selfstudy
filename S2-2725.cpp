#include <iostream>
using namespace std;

int N;
int ans[1001];

int gcd(int a, int b) {
    int tmp;
    while (b) {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main() {
    int C;
    cin >> C;

    ans[1] = 3;
    for (int i = 2; i <= 1000; i++) {
        int cnt = 0;

        for (int j = 1; j < i; j++) {
            if (gcd(i, j) == 1) {
                cnt += 1;
            }
        }

        ans[i] = ans[i - 1] + 2 * cnt;
    }

    while (C--) {
        cin >> N;

        cout << ans[N] << "\n";
    }

    return 0;
}