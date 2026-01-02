#include <iostream>
#include <vector>
using namespace std;

int N, M;
long long ans;
vector<int> vc;

bool check(long long mid) {
    long long cnt = 0;

    for (int i = 0; i < N; i++) {
        cnt += mid / vc[i];
    }

    if (cnt >= M) {
        return true;
    }

    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        vc.push_back(num);
    }

    long long left = 1;
    long long right = 1e15;
    while (left <= right) {
        long long mid = (left + right) / 2;

        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}