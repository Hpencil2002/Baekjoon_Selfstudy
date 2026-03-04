#include <iostream>
#include <algorithm>
using namespace std;

long long N, K;
long long ans;
long long sensor[10001];
long long facility[10001];

int main() {
    cin >> N >> K;

    for (long long i = 1; i <= N; i++) {
        cin >> sensor[i];
    }
    sort(sensor + 1, sensor + N + 1);

    for (long long i = 1; i < N; i++) {
        facility[i] = sensor[i + 1] - sensor[i];
    }
    sort(facility + 1, facility + N, greater<long long>());

    for (long long i = K; i < N; i++) {
        ans += facility[i];
    }

    cout << ans;

    return 0;
}