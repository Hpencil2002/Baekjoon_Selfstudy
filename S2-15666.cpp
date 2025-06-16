#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10];
int arr[10];

void solve(int x, int len) {
    if (len == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = x; i < N; i++) {
        if (num[i] != tmp) {
            arr[len] = num[i];
            tmp = arr[len];
            solve(i, len + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num, num + N);

    solve(0, 0);

    return 0;
}