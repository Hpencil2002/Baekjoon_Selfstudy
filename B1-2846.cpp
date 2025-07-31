#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[1001];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int ans = 0;

    for (int i = 1; i < N; i++) {
        if (arr[i] > arr[i - 1]) {
            if (start == 0) {
                start = arr[i - 1];
            }

            if (i == N - 1) {
                ans = max(ans, arr[i] - start);
            }
        }
        else {
            if (start != 0) {
                ans = max(ans, arr[i - 1] - start);
            }

            start = 0;
        }
    }

    cout << ans;

    return 0;
}