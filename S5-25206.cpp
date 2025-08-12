#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, grade;
    double credit;

    double sumCredit = 0.0;
    double tmp;
    double ans = 0.0;
    for (int i = 0; i < 20; i++) {
        cin >> name >> credit >> grade;
        if (grade == "P") {
            continue;
        }

        sumCredit += credit;

        if (grade == "F") {
            continue;
        }

        if (grade[0] == 'A') {
            tmp = 4;
        }
        else if (grade[0] == 'B') {
            tmp = 3;
        }
        else if (grade[0] == 'C') {
            tmp = 2;
        }
        else {
            tmp = 1;
        }
        if (grade[1] == '+') {
            tmp += 0.5;
        }

        ans += credit * tmp;
    }

    cout << ans / sumCredit;

    return 0;
}