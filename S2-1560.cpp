#include <iostream>
#include <string>
using namespace std;

string N;

int main() {
    cin >> N;
    if (N == "0" || N == "1") {
        cout << N;

        return 0;
    }

    string ans;
    bool plus = false;

    while (N.size() > 0) {
        int a = N.back() - '0';
        N.pop_back();

        a = plus ? a + a + 1 : a + a;
        plus = a > 9 ? true : false;

        ans += to_string(a % 10);
    }
    if (plus) {
        ans += '1';
    }

    bool minus = false;
    int tmp = ans.at(0) - '0' - 2;

    if (tmp < 0) {
        minus = true;
        tmp += 10;
    }
    ans.at(0) = tmp + '0';

    int index = 1;
    while (minus) {
        tmp = ans.at(index) - '0' - 1;

        if (tmp >= 0) {
            ans.at(index) = tmp + '0';

            break;
        }

        tmp += 10;
        ans.at(index) = tmp + '0';

        index += 1;
    }

    if (ans.back() != '0') {
        cout << ans.back();
    }
    for (int i = ans.size() - 2; i > -1; i--) {
        cout << ans.at(i);
    }

    return 0;
}