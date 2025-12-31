#include <iostream>
using namespace std;

int K;
int choco = 1;
int division;

int main() {
    cin >> K;

    while (choco < K) {
        choco *= 2;
    }

    int tmp = choco;
    int cnt = 0;
    while (K != 0) {
        if (K >= tmp) {
            division = cnt;
            K -= tmp;
        }

        tmp /= 2;
        cnt += 1;
    }

    cout << choco << ' ' << division;

    return 0;
}