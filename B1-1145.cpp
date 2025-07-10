#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num[5];
    for (int i = 0; i < 5; i++) {
        cin >> num[i];
    }

    sort(num, num + 5);

    int cnt = 0;
    int ans = num[0] - 1;

    while (cnt < 3) {
        ans += 1;
        cnt = 0;

        for (int i = 0; i < 5; i++) {
            if (ans % num[i] == 0) {
                cnt += 1;
            }
        }
    }

    cout << ans;

    return 0;
}