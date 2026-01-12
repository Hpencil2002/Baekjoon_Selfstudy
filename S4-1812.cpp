#include <iostream>
using namespace std;

int N;
int candy[1000];
int sum;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> candy[i];

        sum += candy[i];
    }
    sum /= 2;

    for (int i = 0; i < N; i++) {
        int tmp = 0;

        for (int j = 0; j < N; j += 2) {
            tmp += candy[(i + j) % N];
        }

        cout << tmp - sum << "\n";
    }

    return 0;
}