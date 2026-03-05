#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];
int ans = 2000000000;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int start = 0;
    int end = 0;
    while (start < N && end < N) {
        int tmp = arr[end] - arr[start];

        if (tmp < M) {
            end += 1;
        }
        else {
            ans = min(ans, tmp);
            start += 1;
        }
    }

    cout << ans;

    return 0;
}