#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100010

int arr[MAX];

int main() {
    int N, K;
    cin >> N >> K;

    int ans = 0;
    for (int i = 2; i <= N; i++) {
        if (arr[i]) {
            continue;
        }

        for (int j = i; j <= N; j += i) {
            arr[j] = max(arr[j], i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i] <= K) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}