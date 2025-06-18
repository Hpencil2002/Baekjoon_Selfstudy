#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans = 1;
vector<string> mp;

bool isSquare(int width) {
    for (int y = 0; y < N - width; y++) {
        for (int x = 0; x < M - width; x++) {
            if (mp[y][x] == mp[y][x + width] && mp[y + width][x] == mp[y + width][x + width] && mp[y][x] == mp[y + width][x]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> N >> M;
    mp = vector<string>(N);
    for (int i = 0; i < N; i++) {
        cin >> mp[i];
    }

    for (int width = min(N, M); width >= 0; width--) {
        if (isSquare(width)) {
            ans = width + 1;
            break;
        }
    }

    cout << ans * ans;

    return 0;
}