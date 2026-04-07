#include <iostream>
#include <cmath>
using namespace std;

int N, M;
bool arr[1001];
int ans = 0x3f3f3f3f;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s;
        cin >> s;

        arr[s] = true;
    }

    for (int i = 1; i <= 1001; i++) {
        if (arr[i]) {
            continue;
        }

        for (int j = 1; j <= 1001; j++) {
            if (arr[j]) {
                continue;
            }

            for (int k = 1; k <= 1001; k++) {
                if (arr[k]) {
                    continue;
                }

                int xyz = i * j * k;
                if (ans > abs(N - xyz)) {
                    ans = abs(N - xyz);
                }

                if (N < xyz) {
                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}