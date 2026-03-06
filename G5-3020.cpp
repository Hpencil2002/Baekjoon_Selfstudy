#include <iostream>
#include <vector>
using namespace std;

int N, H;
vector<int> bottom;
vector<int> top;
vector<int> res;

int main() {
    cin >> N >> H;
    bottom = vector<int>(H + 1, 0);
    top = vector<int>(H + 1, 0);
    res = vector<int>(H + 1, 0);

    for (int i = 0; i < N / 2; i++) {
        int b, t;
        cin >> b >> t;

        bottom[b] += 1;
        top[H + 1 - t] += 1;
    }
    for (int i = H - 1; i >= 1; i--) {
        bottom[i] += bottom[i + 1];
    }

    int minNum = 987654321;
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        top[i] += top[i - 1];
        res[i] += top[i] + bottom[i];

        if (minNum > res[i]) {
            cnt = 1;
            minNum = res[i];
        }
        else if (res[i] == minNum) {
            cnt += 1;
        }
    }

    cout << minNum << ' ' << cnt;

    return 0;
}