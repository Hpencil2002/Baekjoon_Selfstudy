#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[100010];

int main() {
    int T;
    cin >> T;

    while (T--) {
        memset(arr, 0, sizeof(arr));

        int N;
        cin >> N;

        int tmp = N;
        for (int i = 2; i <= tmp; i++) {
            while (tmp % i == 0) {
                tmp /= i;
                arr[i] += 1;
            }
        }

        for (int i = 2; i <= N; i++) {
            if (arr[i]) {
                cout << i << ' ' << arr[i] << "\n";
            }
        }
    }

    return 0;
}