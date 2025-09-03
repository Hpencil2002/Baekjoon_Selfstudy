#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < 1000; i++) {
        if (arr[i] == 1) {
            continue;
        }

        for (int j = 2; i * j < 1000; j++) {
            arr[i * j] += 1;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        int cnt = 0;
        int a[3] = { 0, };
        for (a[0] = 2; a[0] < 1000; a[0]++) {
            if (arr[a[0]] > 0) {
                continue;
            }

            for (a[1] = 2; a[1] < 1000; a[1]++) {
                if (arr[a[1]] > 0) {
                    continue;
                }

                for (a[2] = 2; a[2] < 1000; a[2]++) {
                    if (arr[a[2]] > 0) {
                        continue;
                    }

                    if (a[0] + a[1] + a[2] == K) {
                        cnt += 1;
                        sort(a, a + 3);
                        for (int i = 0; i < 3; i++) {
                            cout << a[i] << ' ';
                        }
                        cout << "\n";
                    }
                }

                if (cnt > 0) {
                    break;
                }
            }

            if (cnt > 0) {
                break;
            }
        }

        if (cnt == 0) {
            cout << "0\n";
        }
    }

    return 0;
}