#include <iostream>
using namespace std;

int arr[41] = { 0, };
int ans1 = 0, ans2 = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        ans1 += 1;
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    cin >> n;

    fib(n);

    arr[1] = arr[2] = 1;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        ans2 += 1;
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}