#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];

int main() {
    int K;
    cin >> K;

    int cnt = 1;
    while (K--) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + N);

        int gap = -1;
        for (int i = 0; i < N - 1; i++) {
            gap = max(gap, arr[i + 1] - arr[i]);
        }

        cout << "Class " << cnt << "\n";
        cout << "Max " << arr[N - 1] << ", Min " << arr[0] << ", Largest gap " << gap << "\n";

        cnt += 1;
    }

    return 0;
}