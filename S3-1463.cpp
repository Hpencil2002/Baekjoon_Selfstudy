#include <iostream>
using namespace std;

int main() {
    int N;
    int *arr;

    cin >> N;
    arr = new int[N + 1];
    arr[1] = 0;

    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] + 1;
        if (!(i % 3)) {
            arr[i] = min(arr[i], arr[i / 3] + 1);
        }
        if (!(i % 2)) {
            arr[i] = min(arr[i], arr[i / 2] + 1);
        }
    }

    cout << arr[N] << "\n";

    return 0;
}