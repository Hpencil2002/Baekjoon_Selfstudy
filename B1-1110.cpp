#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    int ten, one;

    if (N >= 10) {
        ten = N / 10;
        one = N % 10;
    }
    else {
        ten = 0;
        one = N;
    }

    int tmp = ten + one;
    int num = one * 10 + tmp % 10;
    ans += 1;

    while (num != N) {
        if (num >= 10) {
            ten = num / 10;
            one = num % 10;
        }
        else {
            ten = 0;
            one = num;
        }

        tmp = ten + one;
        num = one * 10 + tmp % 10;
        ans += 1;
    }

    cout << ans;

    return 0;
}