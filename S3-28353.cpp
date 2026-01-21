#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int ans;
int arr[5001];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int start = 0;
    int end = N - 1;
    while (start < end) {
        int mid = arr[start] + arr[end];

        if (mid > K) {
            end -= 1;
        }
        else {
            ans += 1;

            start += 1;
            end -= 1;
        }
    }

    cout << ans;

    return 0;
}