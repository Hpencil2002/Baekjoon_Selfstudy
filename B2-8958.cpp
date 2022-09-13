#include <iostream>
#include <string>
using namespace std;

int check(string &s);

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        cout << check(s) << "\n";
    }

    return 0;
}

int check(string &s) {
    int tmp = 0;
    int sum = 0;

    for (char &v : s) {
        if (v == 'O') {
            tmp++;
            sum += tmp;
        }
        else {
            tmp = 0;
        }
    }

    return sum;
}