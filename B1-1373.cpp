#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string num;
    cin >> num;

    while (num.length() % 3 != 0) {
        num = '0' + num;
    }

    for (int i = 0; i < num.length(); i += 3) {
        int ans = (num[i] - '0') * 4 + (num[i + 1] - '0') * 2 + (num[i + 2] - '0');
        cout << ans;
    }

    return 0;
}