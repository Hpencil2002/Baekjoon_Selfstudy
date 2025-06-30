#include <iostream>
using namespace std;

int main() {
    long long N;
    long long fc[20];

    cin >> N;

    fc[0] = 1;
    for (long long i = 1; i < 20; i++) {
        fc[i] = fc[i - 1] * i;
    }

    if (N == 0) {
        cout << "NO";
    }
    else {
        for (int i = 19; i >= 0; i--) {
            if (N >= fc[i]) {
                N -= fc[i];
            }
        }

        if (N) {
            cout << "NO";
        }
        else {
            cout << "YES";
        }
    }

    return 0;
}