#include <iostream>
using namespace std;

int n;
int weight[10001];
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++) {
        if (left <= right) {
            left += weight[i];
        }
        else {
            right += weight[i];
        }
    }

    int diff = -1;
    if (left == right) {
        cout << 0;

        return 0;
    }
    else if (left > right) {
        diff = left - right;
    }
    else {
        diff = right - left;
    }

    if (diff > 0) {
        if (diff / 100 > 0) {
            ans += diff / 100;
            diff %= 100;

            if (diff == 0) {
                cout << ans;

                return 0;
            }
        }
        if (diff / 50 > 0) {
            ans += diff / 50;
            diff %= 50;

            if (diff == 0) {
                cout << ans;

                return 0;
            }
        }
        if (diff / 20 > 0) {
            ans += diff / 20;
            diff %= 20;

            if (diff == 0) {
                cout << ans;

                return 0;
            }
        }
        if (diff / 10 > 0) {
            ans += diff / 10;
            diff %= 10;

            if (diff == 0) {
                cout << ans;

                return 0;
            }
        }
        if (diff / 5 > 0) {
            ans += diff / 5;
            diff %= 5;

            if (diff == 0) {
                cout << ans;

                return 0;
            }
        }
        if (diff / 2 > 0) {
            ans += diff / 2;
            diff %= 2;

            if (diff == 0) {
                cout << ans;

                return 0;
            }
        }

        if (diff == 1) {
            ans += 1;
            cout << ans;
        }
        else {
            cout << ans;
        }
    }

    return 0;
}