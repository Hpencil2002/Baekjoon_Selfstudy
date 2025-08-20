#include <iostream>
using namespace std;

int A[10001];
int ans;

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            tmp += A[j];

            if (tmp == M) {
                ans += 1;
                tmp = 0;
                break;
            }
        }

        if (tmp != 0) {
            tmp = 0;
        }
    }

    cout << ans;

    return 0;
}