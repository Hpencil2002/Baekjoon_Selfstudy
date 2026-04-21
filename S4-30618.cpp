#include <iostream>
using namespace std;

int i;
int N;

int main() {
    cin >> N;
    for (i = 1; i <= N; i += 2) {
        cout << i << ' ';
    }

    if (N % 2 == 0) {
        i = N;
    }
    else {
        i = N - 1;
    }

    for (; i >= 1; i -= 2) {
        cout << i << ' ';
    }

    return 0;
}