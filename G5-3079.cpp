#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
long long arr[100001];
long long ans;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    long long high = M * arr[0];
    long long low = 1;
    long long mid;
    long long people;

    while (high >= low) {
        people = 0;
        mid = (high + low) / 2;
        for (int i = 0; i < N; i++) {
            people += mid / arr[i];
        }

        if (people >= M) {
            if (ans > mid || ans == 0) {
                ans = mid;
            }

            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}