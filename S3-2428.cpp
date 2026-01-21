#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long ans;
double arr[100001];

long long solve(double fileSize, int index) {
    int start = 0;
    int end = index - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] < fileSize * 0.9) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return index - start;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 1; i < N; i++) {
        ans += solve(arr[i], i);
    }

    cout << ans;

    return 0;
}