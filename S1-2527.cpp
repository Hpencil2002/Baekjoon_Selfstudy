#include <iostream>
#include <algorithm>
using namespace std;

int x1, y1, p1, q1, x2, y2, p2, q2;
int xr, xl, yb, yt, xdiff, ydiff;

int main() {
    for (int t = 0; t < 4; t++) {
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

        xl = max(x1, x2);
        xr = min(p1, p2);
        yb = max(y1, y2);
        yt = min(q1, q2);

        xdiff = xr - xl;
        ydiff = yt - yb;

        if (xdiff > 0 && ydiff > 0) {
            cout << "a\n";
        }
        else if (xdiff < 0 || ydiff < 0) {
            cout << "d\n";
        }
        else if (xdiff == 0 && ydiff == 0) {
            cout << "c\n";
        }
        else {
            cout << "b\n";
        }
    }

    return 0;
}