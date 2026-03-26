#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
string rightWord;
int w;
int o;
int l;
int f;

string makeWord(int w) {
    string res;

    for (int i = 0; i < w; i++) {
        res += 'w';
    }
    for (int i = 0; i < w; i++) {
        res += 'o';
    }
    for (int i = 0; i < w; i++) {
        res += 'l';
    }
    for (int i = 0; i < w; i++) {
        res += 'f';
    }

    return res;
}

int main() {
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'w') {
            w += 1;
        }
        else if (str[i] == 'o') {
            o += 1;
        }
        else if (str[i] == 'l') {
            l += 1;
        }
        else if (str[i] == 'f') {
            f += 1;
        }
    }

    if (w != o || w != l || w != f || o != l || o != f || l != f) {
        cout << 0;

        return 0;
    }
    else {
        if (str == makeWord(w)) {
            cout << 1;

            return 0;
        }
        else {
            for (int i = 1; i < w; i++) {
                rightWord = makeWord(w - i);

                while (str.find(rightWord) != -1) {
                    string star = "";
                    for (int j = 0; j < rightWord.size(); j++) {
                        star += '*';
                    }

                    str.replace(str.find(rightWord), rightWord.size(), star);
                }
            }

            for (int i = 0; i < str.size(); i++) {
                if (str[i] != '*') {
                    cout << 0;

                    return 0;
                }
            }

            cout << 1;

            return 0;
        }
    }

    return 0;
}