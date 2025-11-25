#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int num = 0;
    int ptr = 0;

    while (num++ < 30000) {
        string tmp = to_string(num);

        for (int i = 0; i < tmp.size(); i++) {
            if (str[ptr] == tmp[i]) {
                ptr += 1;
            }

            if (ptr == str.size()) {
                cout << num;

                return 0;
            }
        }
    }

    return 0;
}