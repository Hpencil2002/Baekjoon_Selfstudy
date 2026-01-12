#include <iostream>
#include <map>
using namespace std;

int n;
int ans;
map<int, int> xmp, ymp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        xmp[x] += 1;
        ymp[y] += 1;
    }

    for (auto a : xmp) {
        if (a.second >= 2) {
            ans += 1;
        }
    }
    for (auto a : ymp) {
        if (a.second >= 2) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}