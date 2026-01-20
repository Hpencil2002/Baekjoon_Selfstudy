#include <iostream>
#include <string>
using namespace std;

string str;
int xIndex = -1;

int main() {
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'x') {
            xIndex = i;
        }
    }

    if (xIndex < 0) {
        cout << 0;
    }
    else {
        if (xIndex == 0) {
            cout << 1;
        }
        else if (str[xIndex - 1] == '+') {
            cout << 1;
        }
        else if (str[xIndex - 1] == '-') {
            cout << -1;
        }
        else {
            cout << stoi(str.substr(0, xIndex));
        }
    }

    return 0;
}