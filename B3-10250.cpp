#include <iostream>
using namespace std;

int main() {
    int T;
    int H, W, N;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> H >> W >> N;

        int ans_H, ans_W;
        ans_H = N % H;
        ans_W = N / H + 1;

        if (ans_H == 0) {
            ans_H = H;
            ans_W = N / H;
        }

        cout << ans_H * 100 + ans_W << "\n";
    }

    return 0;
}