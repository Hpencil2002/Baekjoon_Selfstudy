#include <iostream>
#include <cmath>
using namespace std;

int H, W;
int height[510];
int ans;

int main() {
    cin >> H >> W;
    for (int i = 1; i <= W; i++) {
        cin >> height[i];
    }

    for (int i = 2; i < W; i++) {
        int left = 0;
        int right = 0;

        for (int j = 1; j < i; j++) {
            left = max(left, height[j]);
        }
        for (int j = i + 1; j <= W; j++) {
            right = max(right, height[j]);
        }

        int res = min(left, right) - height[i];
        if (res >= 0) {
            ans += res;
        }
    }

    cout << ans;

    return 0;
}