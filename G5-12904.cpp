#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;

int main() {
    cin >> S >> T;

    int index = T.size() - 1;
    while (S.size() < T.size()) {
        if (T[index] == 'A') {
            T.pop_back();
        }
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }

        index -= 1;
    }

    if (S == T) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}