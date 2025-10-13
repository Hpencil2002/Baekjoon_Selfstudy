#include <iostream>
#include <algorithm>
using namespace std;

bool visited[9999];

int func(int a, int b, int c, int d) {
    int num1 = a * 1000 + b * 100 + c * 10 + d;
    int num2 = b * 1000 + c * 100 + d * 10 + a;
    int num3 = c * 1000 + d * 100 + a * 10 + b;
    int num4 = d * 1000 + a * 100 + b * 10 + c;

    return min({num1, num2, num3, num4});
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int base = func(a, b, c, d);

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                for (int l = 1; l < 10; l++) {
                    int tmp = func(i, j, k, l);

                    if (visited[tmp]) {
                        continue;
                    }
                    visited[tmp] = 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1111; i <= base; i++) {
        if (visited[i]) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}