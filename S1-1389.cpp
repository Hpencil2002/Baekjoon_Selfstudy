#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

int N, M;
int arr[MAX][MAX];

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && arr[i][j] != 1) {
                arr[i][j] = 10000000;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (arr[j][i] + arr[i][k] < arr[j][k]) {
                    arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }
    }

    int val = 10000000;
    int ans;

    for (int i = 1; i <= N; i++) {
        int tmp = 0;

        for (int j = 1; j <= N; j++) {
            tmp += arr[i][j];
        }

        if (tmp < val) {
            val = tmp;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}