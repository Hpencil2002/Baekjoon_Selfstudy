#include <iostream>
#include <string>
using namespace std;

int main() {
    int check[26] = {0, };
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 97) { //대문자
            check[s[i] - 65] += 1;
        }
        else { //소문자
            check[s[i] - 97] += 1;
        }
    }

    int max = 0, index = 0, cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (check[i] > max) {
            max = check[i];
            index = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (max == check[i]) {
            cnt += 1;
        }
    }

    if (cnt > 1) {
        cout << "?\n";
        return 0;
    }
    else {
        cout << (char) (index + 65) << "\n";
        return 0;
    }
}