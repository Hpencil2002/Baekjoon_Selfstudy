#include <iostream>
#include <algorithm> 
using namespace std;

int N;
int ans;
int arr[11];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int t = N - 3; t >= 1; t--) {
        int itmp = 1;

        for (int i = 1; i <= t; i++) {
            itmp *= arr[i];

            int jtmp = 1;
            for (int j = i + 1; j <= N - 2; j++) {
                jtmp *= arr[j];

                int ktmp = 1;
                for (int k = j + 1; k <= N - 1; k++) {
                    ktmp *= arr[k];

                    int ftmp = 1;
                    for (int f = k + 1; f <= N; f++) {
                        ftmp *= arr[f];
                    }

                    ans = max(ans, itmp + jtmp + ktmp + ftmp);
                }
            }
        }
    }

    cout << ans;

    return 0;
}