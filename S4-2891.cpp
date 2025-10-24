#include <iostream>
using namespace std;

int arr[12];

int main() {
    int N, S, R;
    cin >> N >> S >> R;

    for (int i = 1; i <= N; i++) {
        arr[i] = 1;
    }

    for (int i = 0; i < S; i++) {
        int num;
        cin >> num;
        arr[num] -= 1;
    }
    for (int i = 0; i < R; i++) {
        int num;
        cin >> num;
        arr[num] += 1;
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i] == 2) {
            if (!arr[i - 1]) {
                arr[i] = arr[i - 1] = 1;
                continue;
            }
        }

        if (arr[i] == 2) {
            if (!arr[i + 1]) {
                arr[i] = arr[i + 1] = 1;
                continue;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (!arr[i]) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}