#include <iostream>
using namespace std;

int N, M;
long long comb[32][32];

int main() {
    cin >> N >> M;

    comb[0][0] = 1;
    for (int i = 1; i < 32; i++) {
        comb[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    cout << comb[M - 1][N - 1];

    return 0;
}