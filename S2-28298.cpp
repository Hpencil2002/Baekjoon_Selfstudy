#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
char arr[501][501];
int ans;

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            vector<int> alpha = vector<int>(26);
            for (int k = i; k <= N; k += K) {
                for (int l = j; l <= M; l += K) {
                    alpha[arr[k][l] - 'A'] += 1;
                }
            }

            int maxV = *max_element(alpha.begin(), alpha.end());
            int index = max_element(alpha.begin(), alpha.end()) - alpha.begin();

            ans += ((N * M) / (K * K) - maxV);

            for (int k = i; k <= N; k += K) {
                for (int l = j; l <= M; l += K) {
                    arr[k][l] = index + 'A';
                }
            }
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j];
        }

        cout << "\n";
    }

    return 0;
}