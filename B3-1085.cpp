#include <iostream>
using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int dis[4];
    dis[0] = y;
    dis[1] = x;
    dis[2] = h - y;
    dis[3] = w - x;

    int min = dis[0];
    for (int i = 0; i < 4; i++) {
        if (dis[i] < min) {
            min = dis[i];
        }
    }

    cout << min << "\n";

    return 0;
}