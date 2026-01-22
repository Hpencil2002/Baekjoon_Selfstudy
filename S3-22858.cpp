#include <iostream>
#include <memory.h>
using namespace std;

int N, K;
int S[10001];
int D[10001];
int ans[10001];

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
    }

    while (K--) {
        for (int i = 1; i <= N; i++) {
            ans[D[i]] = S[i];
        }

        memcpy(S, ans, sizeof(S));
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}