#include <iostream>
using namespace std;

int N, a[101], k;

void solve1(int n) {
    for (int i = n; i <= N; i += n) {
        a[i] = 1 - a[i];
    }
}

void solve2(int n) {
    int k = 0;

    for (int i = 1; i <= N / 2; i++) {
        if (n - i < 1 || n + i > N || a[n - i] != a[n + i]) {
            break;
        }

        k = i;
    }
    for (int i = n - k; i <= n + k; i++) {
        a[i] = 1 - a[i];
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    cin >> k;
    while (k--) {
        int p, m;

        cin >> p >> m;
        if (p == 1) {
            solve1(m);
        }
        else {
            solve2(m);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << a[i] << ' ';
        if (i % 20 == 0) {
            cout << "\n";
        }
    }

    return 0;
}