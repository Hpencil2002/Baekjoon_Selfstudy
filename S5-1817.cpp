#include <iostream>
using namespace std;

int N, M, cnt = 1, sum;
int book[100001];

int main() {
    cin >> N >> M;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> book[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        sum += book[i];

        if (sum > M) {
            cnt += 1;
            sum = book[i];
        }
    }

    cout << cnt;

    return 0;
}