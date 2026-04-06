#include <iostream>
using namespace std;

int m, s;
int ans = 1;

int main() {
    scanf("%d:%d", &m, &s);
    if (s >= 30) {
        s -= 30;
    }

    ans += m / 10 + m % 10 + s / 10;

    cout << ans;

    return 0;
}