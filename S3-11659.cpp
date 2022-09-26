#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, i, j;
    int *num, *sum;

    cin >> N >> M;
    num = new int[N];
    sum = new int[N];
    sum[0] = 0;
    for (int k = 1; k < N+1; k++) {
        cin >> num[k];
        sum[k] = sum[k - 1] + num[k];
    }

    while (M--) {
        cin >> i >> j;
        cout << sum[j] - sum[i-1] << "\n";
    }

    return 0;
}