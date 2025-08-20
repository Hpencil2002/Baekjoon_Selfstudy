#include <iostream>
#include <algorithm>
using namespace std;

int ans;

int main() {
    int N, M;
    cin >> N >> M;

    int num[15001];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num, num + N);

    int start = 0;
    int end = 1;
    while (start <= end && end < N) {
        if (num[start] + num[end] == M) {
            ans += 1;
        }

        if (end == N - 1) {
            start += 1;
            end = start + 1;
        }
        else {
            end += 1;
        }
    }

    cout << ans;

    return 0;
}