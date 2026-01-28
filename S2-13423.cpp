#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        int* arr = new int[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + N);

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];

                if (binary_search(arr + i + 1, arr + N, arr[i] + diff)) {
                    ans += 1;
                }
            }
        }

        cout << ans << "\n";
        ans = 0;
    }

    return 0;
}