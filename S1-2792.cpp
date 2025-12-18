#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[300005];
int ans;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + M);

    int left = 1;
    int right = arr[M - 1];
    while (left <= right) {
        int mid = (left + right) / 2;

        int cnt = 0;
        for (int i = 0; i < M; i++) {
            cnt += arr[i] / mid;

            if (arr[i] % mid != 0) {
                cnt += 1;
            }
        }

        if (cnt <= N) {
            right = mid - 1;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}