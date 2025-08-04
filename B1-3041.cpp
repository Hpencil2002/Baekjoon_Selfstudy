#include <iostream>
#include <string>
#include <vector>
using namespace std;

int abs(int a, int b) {
    return a < b ? (b - a) : (a - b);
}

int main() {
    vector<string> vc(4);
    for (int i = 0; i < 4; i++) {
        cin >> vc[i];
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (vc[i][j] != '.') {
                ans += abs(i, (vc[i][j] - 'A') / 4) + abs(j, (vc[i][j] - 'A') % 4);
            }
        }
    }

    cout << ans;

    return 0;
}