#include <iostream>
#include <algorithm>
using namespace std;

long long N;
int dice[6];
int maxNum;
long long ans;

int main() {
    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];

        ans += dice[i];
        maxNum = max(maxNum, dice[i]);
    }

    if (N == 1) {
        cout << ans - maxNum;
    }
    else {
        ans = 0;
        dice[0] = min(dice[0], dice[5]);
        dice[1] = min(dice[1], dice[4]);
        dice[2] = min(dice[2], dice[3]);

        sort(dice, dice + 3);

        int sum1 = dice[0];
        int sum2 = sum1 + dice[1];
        int sum3 = sum2 + dice[2];

        ans += sum3 * 4;
        ans += sum2 * (4 * (N - 2) + 4 * (N - 1));
        ans += sum1 * (4 * (N - 1) * (N - 2) + (N - 2) * (N - 2));

        cout << ans;
    }

    return 0;
}