#include <iostream>
using namespace std;

int N;
int ans;
int x[1500];
int y[1500];

long long getDistance(int i, int j) {
    long long distX = x[i] - x[j];
    long long distY = y[i] - y[j];

    return distX * distX + distY * distY;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                long long a = getDistance(i, j);
                long long b = getDistance(i, k);
                long long c = getDistance(j, k);

                if (a > c) {
                    swap(a, c);
                }
                if (b > c) {
                    swap(b, c);
                }

                if (a + b == c) {
                    ans += 1;
                }
            }
        }
    }

    cout << ans;

    return 0;
}