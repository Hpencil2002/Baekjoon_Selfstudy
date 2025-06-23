#include <iostream>
using namespace std;

int month[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int leapyear(int year) {
    int check = 0;

    if (year % 4 == 0) {
        check = 1;
        if (year % 100 == 0)  {
            check = 0;
        }
        if (year % 400 == 0) {
            check = 1;
        }
    }

    return check;
}

int days(int y, int m) {
    int cnt = 0;

    for (int i = 1; i <= y; i++) {
        for (int j = 0; j < (i == y ? m - 1 : 12); j++) {
            cnt += month[j];
        }

        if (leapyear(i)) {
            cnt += 1;
        }
    }

    if (leapyear(y) == 1 && m < 3) {
        cnt -= 1;
    }

    return cnt;
}

int main() {
    int y, m, d, dy, dm, dd;
    cin >> y >> m >> d >> dy >> dm >> dd;

    if ((dy - y) == 1000) {
        if (dm > m) {
            cout << "gg";
            return 0;
        }

        if (dm == m) {
            if (dd >= d) {
                cout << "gg";
                return 0;
            }
        }
    }
    else if ((dy - y) > 1000) {
        cout << "gg";
        return 0;
    }

    int ans = (days(dy, dm) + dd) - (days(y, m) + d);
    cout << "D-" << ans;

    return 0;
}