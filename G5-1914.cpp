#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N;

void solve(int num, int from, int by, int to) {
    if (num == 1) {
        cout << from << ' ' << to << "\n";
    }
    else {
        solve(num - 1, from, to, by);
        cout << from << ' ' << to << "\n";
        solve(num - 1, by, from, to);
    }
}

int main() {
    cin >> N;

    string str = to_string(pow(2, N));

    int index = str.find('.');
    str = str.substr(0, index);
    str[str.length() - 1] -= 1;

    cout << str << "\n";
    if (N <= 20) {
        solve(N, 1, 2, 3);
    }

    return 0;
}