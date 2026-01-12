#include <iostream>
#include <cstring>
using namespace std;

int T;
int N;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        memset(arr, 0, sizeof(arr));

        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        int cur = arr[1];
        int ans = 1;

        while (cur != N && ans <= N) {
            cur = arr[cur];
            ans += 1;
        }

        cout << (ans > N ? 0 : ans) << "\n";
    }

    return 0;
}