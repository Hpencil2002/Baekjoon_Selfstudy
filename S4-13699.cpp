#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long t[36] = { 0, };
    t[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < i; j++) {
            t[i] += t[j] * t[i - j - 1];
        }
    }

    cout << t[n];

    return 0;
}