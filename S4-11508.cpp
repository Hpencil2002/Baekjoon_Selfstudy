#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int C[100001];
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    sort(C, C + N, greater<int>());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if ((i + 1) % 3 == 0) {
            continue;
        }
        else {
            ans += C[i];
        }
    }

    cout << ans;

    return 0;
}