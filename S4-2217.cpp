#include <iostream>
#include <algorithm>
using namespace std;

int rope[100001];
int current, ans;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> rope[i];
    }

    sort(rope, rope + N);

    ans = rope[N - 1];
    for (int i = N - 1; i >= 0; i--) {
        current = rope[i] * (N - i);

        if (ans < current) {
            ans = current;
        }
    }

    cout << ans;

    return 0;
}