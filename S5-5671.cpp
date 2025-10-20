#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string room) {
    vector<int> cnt = vector<int>(10, 0);
    for (int i = 0; i < room.size(); i++) {
        cnt[room[i] - '0'] += 1;
    }

    for (int i = 0; i < 10; i++) {
        if (cnt[i] >= 2) {
            return false;
        }
    }

    return true;
}

int main() {
    int N, M;

    while (cin >> N >> M) {
        int ans = 0;

        for (int i = N; i <= M; i++) {
            string room  = to_string(i);
            if (isValid(room)) {
                ans += 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}