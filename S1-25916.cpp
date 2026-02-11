#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int arr[500001];
int ans;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = 0;
    int sum = 0;

    while (end <= N + 1) {
        if (sum > M) {
            sum -= arr[start];

            start += 1;
        }
        else if (sum <= M) {
            ans = max(ans, sum);
            sum += arr[end];

            end += 1;
        }
    }

    cout << ans;

    return 0;
}