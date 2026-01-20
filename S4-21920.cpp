#include <iostream>
using namespace std;

int N;
int arr[500001];
int X;
double cnt;
double ans;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> X;

    for (int i = 0; i < N; i++) {
        int num = X > arr[i] ? gcd(X, arr[i]) : gcd(arr[i], X);

        if (num == 1) {
            cnt += 1;
            ans += arr[i];
        }
    }

    cout.precision(7);
    cout << ans / cnt;

    return 0;
}