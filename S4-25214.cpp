#include <iostream>
using namespace std;

int arr[200000];
int minV;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (i == 0) {
            arr[0] = 0;
            minV = x;
        }
        else {
            if (x < minV) {
                minV = x;
            }

            arr[i] = (x - minV) > arr[i - 1] ? (x - minV) : arr[i - 1];
        }

        cout << arr[i] << ' ';
    }

    return 0;
}