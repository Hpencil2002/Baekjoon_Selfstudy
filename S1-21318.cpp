#include <iostream>
using namespace std;

long long N;
long long arr[100005];
long long Q;
long long x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if (i != 0) {
            if (arr[i - 1] > arr[i]) {
                arr[i - 1] = 1;
            }
            else {
                arr[i - 1] = 0;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        arr[i] += arr[i - 1];
    }

    cin >> Q;
    while (Q--) {
        cin >> x >> y;

        if (x >= 2 && y >= 2) {
            cout << arr[y - 2] - arr[x - 2] << "\n";
        }
        else if (y == 1) {
            cout << "0\n";
        }
        else {
            cout << arr[y - 2] << "\n";
        }
    }

    return 0;
}