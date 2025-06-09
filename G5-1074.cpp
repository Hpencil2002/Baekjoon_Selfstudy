#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int ans = 0;

void DC(int x, int y, int size) {
    if (c == x && r == y) {
        cout << ans;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y) {
        DC(x, y, size / 2);
        DC(x + size / 2, y, size / 2);
        DC(x, y + size / 2, size / 2);
        DC(x + size / 2, y + size / 2, size / 2);
    }
    else {
        ans += size * size;
    }
}

int main() {
    cin >> N >> r >> c;
    DC(0, 0, pow(2, N));

    return 0;
}