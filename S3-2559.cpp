#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K, temper[100000];
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> temper[i];
    }

    int sum = 0, cnt = 0, max_val = -900000;
    for (int i = 0; i < N; i++) {
        sum += temper[i];
        cnt += 1;
        if (cnt == K) {
            max_val = max(max_val, sum);
            sum -= temper[i - (K - 1)];
            cnt -= 1;
        }
    }

    cout << max_val << "\n";

    return 0;
}