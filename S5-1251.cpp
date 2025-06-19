#include <iostream>
#include <string>
using namespace std;

string input, result;
string a, b;

int main() {
    cin >> input;
    result = "{";

    for (int i = 0; i < input.size() - 2; i++) {
        for (int j = i + 1; j < input.size() - 1; j++) {
            string tmp;

            for (int k = i; k >= 0; k--) {
                tmp += input[k];
            }
            for (int k = j; k > i; k--) {
                tmp += input[k];
            }
            for (int k = input.size() - 1; k > j; k--) {
                tmp += input[k];
            }

            if (result > tmp) {
                result = tmp;
            }
        }
    }

    cout << result;

    return 0;
}