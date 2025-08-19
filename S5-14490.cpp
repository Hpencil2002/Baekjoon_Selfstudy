#include <iostream>
#include <string>
#include <numeric>
using namespace std;

int main() {
    string sn = "", sm = "";
    string str;

    cin >> str;
    int index = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ':') {
            sn += str[i];
        }
        else {
            index = i;
            break;
        }
    }
    for (int i = index + 1; i < str.size(); i++) {
        sm += str[i];
    }

    int n = stoi(sn);
    int m = stoi(sm);
    int tmp = gcd(n, m);

    cout << n / tmp << ':' << m / tmp;

    return 0;
}