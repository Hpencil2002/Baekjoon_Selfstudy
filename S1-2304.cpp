#include <iostream>
#include <algorithm>
using namespace std;

int N;
int maxPos, maxH;
int ans;
int arr[1001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int L, H;
        cin >> L >> H;

        arr[L] = H;
        if (maxH < H) {
            maxPos = L;
            maxH = H;
        }
    }

    int leftH = 0;
    for (int i = 1; i < maxPos; i++) {
        leftH = max(leftH, arr[i]);
        ans += leftH;
    }

    int rightH = 0;
    for (int i = 1000; i > maxPos; i--) {
        rightH = max(rightH, arr[i]);
        ans += rightH;
    }

    cout << ans + maxH;

    return 0;
}