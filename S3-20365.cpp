#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    string str;

    cin >> N >> str;

    int R = 0, B = 0;
    if (str[0] == 'B') {
        B += 1;
    }
    else {
        R += 1;
    }

    for (int i = 1; i < N; i++) {
        if (str[i] == 'B' && str[i - 1] == 'R') {
            B += 1;
        }
        if (str[i] == 'R' && str[i - 1] == 'B') {
            R += 1;
        }
    }

    cout << min(R, B) + 1;

    return 0;
}