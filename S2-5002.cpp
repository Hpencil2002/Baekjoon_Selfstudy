#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int X;
string str;

int main() {
    cin >> X;
    cin >> str;

    int m = 0, w = 0;
    int tmp = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'M') {
            m += 1;
        }
        else {
            w += 1;
        }
        tmp = abs(m - w);

        if (tmp > X) {
            if (i == str.length() - 1) {
                if (str[i] == 'M') {
                    m -= 1;
                }
                else {
                    w -= 1;
                }

                break;
            }
            else {
                if (str[i] == str[i + 1]) {
                    if (str[i] == 'M') {
                        m -= 1;
                    }
                    else {
                        w -= 1;
                    }

                    break;
                }
                else {
                    if (str[i] == 'M') {
                        m -= 1;
                    }
                    else {
                        w -= 1;
                    }

                    swap(str[i], str[i + 1]);
                    i -= 1;
                }
            }
        }
    }

    cout << m + w;

    return 0;
}