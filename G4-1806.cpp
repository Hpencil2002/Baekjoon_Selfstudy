#include <iostream>
#include <cmath>
using namespace std;

int N, S;
int arr[100001];
int ans = INT32_MAX;

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int start = 1, end = 1;
    int sum = arr[1];
    while (start <= end && end <= N) {
        if (sum >= S) {
            ans = min(ans, end - start + 1);
        }

        if (sum < S) {
            end += 1;
            sum += arr[end];
        }
        else {
            sum -= arr[start];
            start += 1;
        }
    }

    if (ans == INT32_MAX) {
        cout << 0;
    }
    else {
        cout << ans;
    }

    return 0;
}