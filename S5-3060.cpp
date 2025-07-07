#include <iostream>
#include <algorithm>
using namespace std;

int pig[6] = { 0, };
int prev_pig[6] = { 0, };

int calc(int day) {
    int res = 0;

    if (day != 1) {
        for (int i = 0; i < 6; i++) {
            int left = (i + 6 - 1) % 6;
            int right = (i + 6 + 1) % 6;
            int opp = (i + 3) % 6;

            pig[i] = prev_pig[i] + prev_pig[left] + prev_pig[right] + prev_pig[opp];
        }

        copy(pig, pig + 6, prev_pig);
    }

    for (int i = 0; i < 6; i++) {
        res += pig[i];
    }

    return res;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int day = 1;
        int N = 0;

        cin >> N;
        for (int i = 0; i < 6; i++) {
            cin >> pig[i];
            prev_pig[i] = pig[i];
        }

        while (true) {
            int feed = calc(day);

            if (feed > N) {
                cout << day << "\n";
                break;
            }

            day += 1;
        }
    }

    return 0;
}