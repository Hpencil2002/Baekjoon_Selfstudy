#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, y, N, dir, dis, dg;
int ans;
vector<int> vc;

int main() {
    cin >> x >> y >> N;

    for (int i = 0; i < N; i++) {
        cin >> dir >> dis;

        if (dir == 1) {
            vc.push_back(dis);
        }
        else if (dir == 2) {
            vc.push_back(2 * x + y - dis);
        }
        else if (dir == 3) {
            vc.push_back(2 * (x + y) - dis);
        }
        else if (dir == 4) {
            vc.push_back(dis + x);
        }
    }

    cin >> dir >> dis;
    if (dir == 1) {
        dg = dis;
    }
    else if (dir == 2) {
        dg = 2 * x + y - dis;
    }
    else if (dir == 3) {
        dg = 2 * (x + y) - dis;
    }
    else if (dir == 4) {
        dg = dis + x;
    }

    for (int i = 0; i < N; i++) {
        int tmp = abs(vc[i] - dg);
        ans += min(tmp, 2 * (x + y) - tmp);
    }

    cout << ans;

    return 0;
}