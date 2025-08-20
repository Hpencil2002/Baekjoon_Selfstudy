#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    int index = 0;
    while (true) {
        if (S[index] == 'p' && S[index + 1] == 'i') {
            index += 2;
        }
        else if (S[index] == 'k' && S[index + 1] == 'a') {
            index += 2;
        }
        else if (S[index] == 'c' && S[index + 1] == 'h' && S[index + 2] == 'u') {
            index += 3;
        }
        else {
            break;
        }

        if (index == S.size()) {
            break;
        }
    }

    if (index != S.size()) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}