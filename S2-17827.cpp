#include <iostream>
using namespace std;

long long N, M, V;
long long arr[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    while (M--) {
        long long K;
        cin >> K;

        if (K < V - 1) {
            cout << arr[K] << "\n";
        }
        else {
            long long index = (K - (V - 1)) % (N - V + 1);

            cout << arr[V - 1 + index] << "\n";
        }
    }

    return 0;
}