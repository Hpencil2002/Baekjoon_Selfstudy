#include <iostream>
using namespace std;

int N, M;
int ans;
int arr[100002];

int main() {
    cin >> N >> M;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int left = 1;
    int right = sum;
    int total;
    while (left <= right) {
        int mid = (left + right) / 2;
        total = mid;

        bool pass = true;
        int cnt = 1;
        for (int i = 0; i < N; i++) {
            int money = arr[i];

            if (money > mid) {
                pass = false;
                break;
            }

            if (money > total) {
                total = mid;
                cnt += 1;
            }

            total -= money;
        }

        if (!pass || cnt > M) {
            left = mid + 1;
        }
        else {
            ans = mid;
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}