#include <iostream>
using namespace std;

int main() {
    int arr[101][101] = { 0, };
    int ans = 0;

    for (int n = 0; n < 4; n++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                if (arr[i][j] == 0) {
                    arr[i][j] = 1;
                    ans += 1;
                }
            }
        }
    }

    cout << ans;

    return 0;
}