#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;

    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (i % 5 == 0) cnt += 1;
        if (i % 25 == 0) cnt += 1;
        if (i % 125 == 0) cnt += 1;
    }

    cout << cnt;

    return 0;
}