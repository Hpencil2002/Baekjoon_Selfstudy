#include <iostream>
using namespace std;

int N, Q;
int arr[(int)1e6 + 1];
int s, e;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        arr[i] = arr[i - 1] ^ a;
    }

    while (Q--) {
        cin >> s >> e;

        ans ^= (arr[e] ^ arr[s - 1]);
    }

    cout << ans;

    return 0;
}