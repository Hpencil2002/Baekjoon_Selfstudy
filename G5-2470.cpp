#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100000];
int ans[2];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int start = 0;
    int end = N - 1;
    int tmp = 2000000001;

    while (start < end) {
        int sum = arr[start] + arr[end];

        if (abs(sum) < tmp) {
            ans[0] = arr[start];
            ans[1] = arr[end];
            tmp = abs(sum);
        }

        if (sum < 0) {
            start += 1;
        }
        else {
            end -= 1;
        }
    }

    sort(ans, ans + 2);

    for (int i = 0; i < 2; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}