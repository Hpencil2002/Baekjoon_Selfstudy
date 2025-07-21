#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = N; i >= 0; i--) {
        int tmp, flag;
        tmp = i;
        flag = 1;

        while (tmp != 0) {
            if (tmp % 10 != 4 && tmp % 10 != 7) {
                flag = 0;
                break;
            }
            else {
                tmp /= 10;
            }
        }

        if (flag == 1) {
            cout << i;
            break;
        }
    }

    return 0;
}