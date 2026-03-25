#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int xs, ys, xe, ye;
int dx, dy;
int ansX, ansY;
int dist = 1000000;

int gcd(int a, int b) {
    if (!a || !b) {
        return 0;
    }

    if (a < b) {
        swap(a, b);
    }

    while (a % b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return b;
}

int main() {
    cin >> xs >> ys;
    cin >> xe >> ye >> dx >> dy;

    int d = abs(gcd(dx, dy));

    if (dx || dy) {
        if (!dy) {
            dx = 1;
        }
        else if (!dx) {
            dy = 1;
        }
        else {
            dx /= d;
            dy /= d;
        }
    }
    else if (!dx && !dy) {
        cout << xe << ' ' << ye;

        return 0;
    }

    while (xe >= -100 && xe <= 100 && ye >= -100 && ye <= 100) {
        int next = (xs - xe) * (xs - xe) + (ys - ye) * (ys - ye);

        if (next < dist) {
            dist = next;
            ansX = xe;
            ansY = ye;
        }

        xe += dx;
        ye += dy;
    }

    cout << ansX << ' ' << ansY;

    return 0;
}