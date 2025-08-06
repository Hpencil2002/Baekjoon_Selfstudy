#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int a[101] = { 0, };
    int b[101] = { 0, };
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(a[i] - b[i]);
    }

    cout << ans / 2;

    return 0;
}