#include <iostream>
using namespace std;

int N;
unsigned long long cnt;
int arr[1001][1001];

int main() {
    cin >> N;

    unsigned long long left = 0;
    unsigned long long right = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            cnt += arr[i][j];

            if (arr[i][j] > right) {
                right = arr[i][j];
            }
        }
    }

    while (left + 1 < right) {
        unsigned long long mid = (left + right) / 2;
        unsigned long long sum = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sum += (mid > arr[i][j]) ? arr[i][j] : mid;
            }
        }

        if (((double)sum / cnt) >= 0.5) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    cout << right;

    return 0;
}