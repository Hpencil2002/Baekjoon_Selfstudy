#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, T, flag;
    cin >> A >> T >> flag;

    int arr[2001];
    string str;

    for (int i = 0; i <= 1000; i++) {
        str += "0101";

        string tmp = "";
        for (int j = 0; j <= i + 1; j++) {
            tmp += "0";
        }
        str += tmp;

        tmp = "";
        for (int j = 0; j <= i + 1; j++) {
            tmp += "1";
        }
        str += tmp;
    }

    int cnt = 0;
    int index = -1;
    if (flag == 0) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0') {
                cnt += 1;
                if (cnt == T) {
                    index = i;
                    break;
                }
            }
        }
    }
    else if (flag == 1) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1') {
                cnt += 1;
                if (cnt == T) {
                    index = i;
                    break;
                }
            }
        }
    }

    cout << index % A;

    return 0;
}