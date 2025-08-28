#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long tip[100001];
    for (int i = 0; i < N; i++) {
        cin >> tip[i];
    }

    sort(tip, tip + N, greater<long long>());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (tip[i] - i > 0) {
            ans += tip[i] - i;
        }
    }

    cout << ans;

    return 0;
}