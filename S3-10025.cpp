#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main() {
    int N, K;
    cin >> N >> K;

    int maxIndex = 0;
    for (int i = 0; i < N; i++) {
        int g, x;
        cin >> g >> x;

        arr[x] = g;
        if (x > maxIndex) {
            maxIndex = x;
        }
    }

    int sum = 0;
    for (int i = 0; i <= 2 * K; i++) {
        if (i >= 1000001) {
            break;
        }

        sum += arr[i];
    }

    int ans = sum;
    int start = 0;
    for (int i = 2 * K + 1; i <= maxIndex; i++) {
        sum += arr[i];
        sum -= arr[start];
        ans = max(ans, sum);

        start += 1;
    }

    cout << ans;

    return 0;
}