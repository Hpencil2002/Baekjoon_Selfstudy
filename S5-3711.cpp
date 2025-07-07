#include <iostream>
using namespace std;

int arr[300] = { 0, };

int main() {
    int N;
    cin >> N;

    while (N--) {
        int G;
        cin >> G;

        for (int i = 0; i < G; i++) {
            cin >> arr[i];
        }

        int ans = 0;
        while (true) {
            ans += 1;
            int retry = 0;
            int extra[100001] = { 0, };

            for (int i = 0; i < G; i++) {
                extra[arr[i] % ans] += 1;

                if (extra[arr[i] % ans] > 1) {
                    retry += 1;
                    break;
                }
            }

            if (retry > 0) {
                continue;
            }

            cout << ans << "\n";
            break;
        }
    }

    return 0;
}