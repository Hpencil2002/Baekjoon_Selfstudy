#include <iostream>
#include <algorithm>
using namespace std;

int d1, d2;
int ans = 1;
bool chair[2001][2001];

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }

    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    cin >> d1 >> d2;

    for (int i = d1; i <= d2; i++) {
        for (int j = 1; j < i; j++) {
            int mod = gcd(i, j);
            int a = j / mod;
            int b = i / mod;

            if (chair[a][b] == 0) {
                ans += 1;
                chair[a][b] = 1;
            }
        }
    }

    cout << ans;

    return 0;
}