#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long K;
int ans;
vector<int> vc;

int main() {
    cin >> N >> K;

    vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    int start = 1;
    int end = 1000000001;

    while (start <= end) {
        int mid = (start + end) / 2;

        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (vc[i] < mid) {
                sum += mid - vc[i];
            }
        }

        if (K < sum) {
            end = mid - 1;
        }
        else {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans;

    return 0;
}