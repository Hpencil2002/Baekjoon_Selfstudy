#include <iostream>
using namespace std;

int N, Q;
bool arr[2 << 20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;

    while (Q--) {
        int x;
        cin >> x;

        int ans = 0;
        int tmp = x;
        while (tmp > 1) {
            if (arr[tmp]) {
                ans = tmp;
            }

            int next = tmp / 2;
            tmp = next;
        }

        arr[x] = true;
        cout << ans << "\n";
    }

    return 0;
}