#include <iostream>
using namespace std;

int prime[1000000] = { 0, };

void check() {
    for (int i = 2; i * i <= 1000000; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j <= 1000000; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    check();

    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            return 0;
        }

        bool check = false;

        for (int i = 3; i <= n; i += 2) {
            if (prime[i] == 0 && prime[n - i] == 0) {
                cout << n << " = " << i << " + " << n - i << "\n";
                check = true;
                break;
            }
        }

        if (!check) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}