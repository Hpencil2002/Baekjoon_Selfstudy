#include <iostream>
#include <cmath>
using namespace std;

int N;
long long arr[100001];
long long minAns, maxAns;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = N - 1;

    int resSum = abs(arr[left] + arr[right]);
    minAns = arr[left];
    maxAns = arr[right];

    while (left < right) {
        long long tmpSum = arr[left] + arr[right];
        if (abs(tmpSum) < resSum) {
            resSum = abs(tmpSum);
            minAns = arr[left];
            maxAns = arr[right];
        }

        if (tmpSum < 0) {
            left += 1;
        }
        else {
            right -= 1;
        }
    }

    cout << minAns << ' ' << maxAns;

    return 0;
}