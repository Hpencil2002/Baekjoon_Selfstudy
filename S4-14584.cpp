#include <iostream>
#include <string>
using namespace std;

int N;
string str;
string word[21];

int main() {
    cin >> str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word[i];
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < N; j++) {
            if (str.find(word[j]) != string::npos) {
                cout << str;

                return 0;
            }
        }

        for (int j = 0; j < str.length(); j++) {
            str[j] = (str.at(j) - 'a' + 1) % 26 + 'a';
        }
    }
}