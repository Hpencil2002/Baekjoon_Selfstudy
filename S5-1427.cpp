#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;
    int len = num.length();

    for (int i = 0; i < len; i++) {
        int max = num[i];
        int cnt = i;

        for (int j = i; j < len; j++) {
            if (num[j] > max) {
                max = num[j];
                cnt = j;
            }
        }

        if (max > num[i]) {
            int tmp = num[i];
            num[i] = num[cnt];
            num[cnt] = tmp;
        }
    }

    cout << num;

    return 0;
}