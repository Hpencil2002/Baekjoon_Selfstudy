#include <iostream>
using namespace std;

int main() {
    int N, M, J;
    cin >> N >> M >> J;

    int ans = 0;
    int left = 1, right = M;
    while (J--) {
        int pos;
        cin >> pos;

        while(left > pos || right < pos) {
            if (pos > right) {
                right += 1;
                ans += 1;
                left += 1;
            }
            else if (pos < left) {
                right -= 1;
                ans += 1;
                left -= 1;
            }
        }
    }

    cout << ans;

    return 0;
}