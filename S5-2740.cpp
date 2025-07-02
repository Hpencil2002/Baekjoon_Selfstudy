#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    int A[101][101];
    int B[101][101];

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cin >> M >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }

    int ans[101][101] = { 0, };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                ans[i][j] += A[i][k] * B[k][j];
            }

            cout << ans[i][j] << ' ';
        }

        cout << "\n";
    }

    return 0;
}