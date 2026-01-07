#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<long long, long long> arr[3001];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < N; i++) {
        cin >> arr[i].second;
    }

    long long time = max(arr[N -1].first, arr[N - 1].second);
    for (int i = N - 2; i >= 0; i--) {
        long long dis = arr[i + 1].first - arr[i].first;

        if (time + dis <= arr[i].second) {
            time = arr[i].second;
        }
        else {
            time += dis;
        }
    }

    cout << time + arr[0].first;

    return 0;
}